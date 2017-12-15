#include "functionTable.h"

// int FunctionTable::found(const std::string& name) const {
//   std::map<std::string, const Node*>::const_iterator it = functions.find(name);
//   if ( it != functions.end() ){
//     return it->second->getCreateScope();
//   }
//   else
//     return -1;
// }
bool FunctionTable::found(const std::string& name) const {
  std::map<std::string, const Node*>::const_iterator it = functions.find(name);
  if ( it == functions.end() ){
    return false;
  }
  else
    return true;
}

void FunctionTable::insert(const std::string& name, const Node* suite) {
  functions[name] = suite;
}

void FunctionTable::insertPara(const std::string& name, const Node* para) {
  parameters[name] = para;
}

const Node* FunctionTable::getValue(const std::string& name) const {
  std::map<std::string, const Node*>::const_iterator it = functions.find(name);
  if ( it == functions.end() )
    // throw name + std::string(" NOT FOUND!" );
    return NULL;
  else
    return it->second;
}


const Node* FunctionTable::getPara(const std::string& name) const {
  std::map<std::string, const Node*>::const_iterator it = parameters.find(name);
  if (it == parameters.end()) return NULL;
  return it->second;
}


void FunctionTable::display() const{
  std::map<std::string, const Node*>::const_iterator it = functions.begin();
  while (it != functions.end()) {
    std::cout << "functioTable: " << it->first << std::endl;
    it++;
  }
}
