#include "paraTable.h"

bool ParaTable::found(const std::string& name) const {
  std::map<std::string, const Node*>::const_iterator it = parameters.find(name);
  if ( it == parameters.end() ){
    return false;
  }
  else
    return true;
}

void ParaTable::insert(const std::string& name, const Node* fmls) {
  parameters[name] = fmls;
}

const Node* ParaTable::getValue(const std::string& name) const {
  std::map<std::string, const Node*>::const_iterator it = parameters.find(name);
  if ( it == parameters.end() )
    // throw name + std::string(" NOT FOUND!" );
    return NULL;
  else
    return it->second;
}
void ParaTable::display() const{
  std::map<std::string, const Node*>::const_iterator it = parameters.begin();
  while (it != parameters.end()) {
    std::cout << "paraTable: " << it->first << std::endl;
    it++;
  }
}
