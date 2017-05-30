#include "Disease.h"

Disease::Disease(std::string name, std::vector<std::string> li) : p_name(name), p_list(li) {
}

const std::string &Disease::name() const {
  return p_name;
}

const std::vector<std::string> &Disease::riskfulGenes() const {
  return p_list;
}

Disease::~Disease() {
}
