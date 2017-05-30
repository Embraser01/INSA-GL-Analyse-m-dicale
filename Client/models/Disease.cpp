#include "Disease.h"

const std::string &Disease::name() const {
    return p_name;
}

Disease::Disease(const std::string &p_name) : p_name(p_name) {}
