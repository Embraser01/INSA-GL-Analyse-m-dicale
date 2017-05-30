#ifndef MEDANALYSIS_CLIENT_DISEASE_H
#define MEDANALYSIS_CLIENT_DISEASE_H

#include <string>

class Disease {
 public:

  Disease(const std::string &p_name);

  const std::string &name() const;

 private:
  std::string p_name;
};

#endif //MEDANALYSIS_CLIENT_DISEASE_H
