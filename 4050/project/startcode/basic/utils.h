#ifndef _UTILS_H
#define _UTILS_H


#define square(x) ((x)*(x))

#define max2(x,y) (((x)>=(y))?(x):(y))
#define min2(x,y) (((x)>=(y))?(y):(x))
#define max3(x,y,z) (((x)>=(y)&&(x)>=(z))?(x):(((y)>=(x)&&(y)>=(z))?(y):(z)))
#define min3(x,y,z) (((x)<=(y)&&(x)<=(z))?(x):(((y)<=(x)&&(y)<=(z))?(y):(z)))
#define max4(x,y,z,w) (max2(max2((x),(y)),max2((z),(w))))
#define min4(x,y,z,w) (min2(min2((x),(y)),min2((z),(w))))
#define mid3(x,y,z) ( (((y)<(x))&&((x)<(z))) ? (x) : \
		      ( (((z)<(x))&&((x)<(y))) ? (x) : \
		        ( (((x)<(y))&&((y)<(z))) ? (y) : \
		          ( (((z)<(y))&&((y)<(x))) ? (y) : (z) ))))

// Set the mask by Wolfgang
typedef enum {SMOOTH, DART, REG_CREASE, IRR_CREASE, CORNER} code;
// Mask of end even vertices for interior odd vertices
const float IN_ODD_ADJ = 0.375f;
// Mask of opposite even vertices for interior odd vertices
const float IN_ODD_OPP = 0.125f;
// Mask of end even vertices for boundary odd vertices
const float BD_ODD_ADJ = 0.5f;
// Mask for interior even vertices whose degrees are equals to 3
const float IN_EVEN_E3 = 0.4275f;
const float IN_EVEN_E3_NEIBOR = 0.1875f;
// Mask for interior even vertices whose degrees are greater than 3
const float IN_EVEN_G3 = 0.625f;
const float IN_EVEN_G3_NEIBOR = 0.375f;
// Mask of end even vertices for boundary odd vertices
const float BD_EVEN_MID = 0.75f;
const float BD_EVEN_END = 0.125f;

const float twopi = 6.28318530717958647692f;
// This table is used for sharp edges
static const int mask_table[5][5] =
{
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 2, 3, 3},
    {1, 1, 3, 2, 2},
    {1, 1, 3, 2, 2},
};

// Set limit subdivison time by Wolfgang
#define SUB_LIMIT 4

// NOTE:  These primes are used for hashing, and should
// not be the same as any of the primes used as sizes of
// the hash tables (see utils.cpp)
#define LARGE_PRIME_A 10007
#define LARGE_PRIME_B 11003
#define LARGE_PRIME_C 12007
#define LARGE_PRIME_D 13001

// a list of primes...  roughly 2 times as big as previous
//  chosen randomishly from a web listing
static  unsigned int  primes[] = {
        11,
        37,
        79,
       127,
       239,
       421,
      1021,
      2383,
      5749,
      7127,
     10079,
     13627,
     16007,
     21163,
     46307,
     78191,
    100459,
    213977,
    453137,
   1299827,
   2599829,
   5399833,
  11099833,
  24099857,
  52099877,
 100000000};

#define MAX_PRIME 100000000

inline int NextLargestPrime(unsigned int x) {
  if (x > MAX_PRIME) {
    printf("ERROR! requested size (%d) for hash table is too large (max %d)\n",
	   x, MAX_PRIME);
    return x;
  }
  int i = 0;
  while (x > primes[i]) i++;
  return primes[i];
}

#endif
