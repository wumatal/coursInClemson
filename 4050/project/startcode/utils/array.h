#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// ======================================================================
// A resizing array.  but remove is slow & changes the element order.

template <class ARRAY_ELEMENT>
class Array {

public:

  Array(int s) {
    assert (s > 0);
    size = s;
    count = 0;
    data = new ARRAY_ELEMENT [size];
  }
  virtual ~Array() {
    delete [] data;
    data = NULL;
  }

  // =========
  // ACCESSORS
  int Count() const { return count; }
  // Add size() by Wolfgang
  int Size() const { return size; }

  ARRAY_ELEMENT operator [] (int i) const {
    assert (i >= 0 && i < count);
    return data[i];
  }

  // =========
  // MODIFIERS
  void Add(const ARRAY_ELEMENT elem, int index ) {
    if (count == size) {
      // double the space & copy
      int new_size = size*2;
      //printf ("need to resize array from %d to %d\n", size, new_size);
      ARRAY_ELEMENT * new_data = new ARRAY_ELEMENT [new_size];
      for (int i = 0; i < size; i++) {
	       new_data[i] = data[i];
      }
      delete [] data;
      data = new_data;
      size = new_size;
    }
    assert (count < size);
    if( index == -1)
      data[count] = elem;
    else
      data[index] = elem;
    count++;
  }

  void AddNoDuplicates(const ARRAY_ELEMENT e) {
    if (!Member(e))
      Add(e);
  }

  ARRAY_ELEMENT Replace(int i, const ARRAY_ELEMENT elem) {
    assert(i >= 0 && i < count);
    ARRAY_ELEMENT answer = data[i];
    data[i] = elem;
    return answer;
  }

  void Remove(const ARRAY_ELEMENT elem) {
    int x = -1;
    for (int i = 0; i < count; i++) {
      if (data[i] == elem) {
      	x = i;
      	break;
      }
    }
    assert (x >= 0);
    data[x] = data[count-1];
    count--;
  }

  int Member(const ARRAY_ELEMENT elem) const {
    //int x = -1;
    for (int i = 0; i < count; i++) {
      if (data[i] == elem) {
      	//x = i;
      	//break;
        return 1;
      }
    }
    //if (x >= 0) return 1;
    return 0;
  }


  void Clear() {
    count = 0;
  }

  void DeleteAllElements() {
    for (int i = 0; i < count; i++) {
      delete data[i];
    }
    count = 0;
  }

  // Add Copy() by Wolfgang
  void Copy(Array<ARRAY_ELEMENT>* array) {
    int dcout;
    //count = dcout = data->Count();
    dcout = array->Count();
    //size = data->Size();
    for(int i=0; i < dcout; i++) {
      AddNoDuplicates(array->data[i]);
    }
  }

  // debug func by Wolfgang
  void Print() {
    printf ("ARRAY::PRINT %d %d\n",size,count);
    for (int i = 0; i < count; i++) {
    	data[i]->Print();
    }
  }

private:

  // ==============
  // REPRESENTATION
  int count;
  int size;
  ARRAY_ELEMENT * data;

};


#endif
