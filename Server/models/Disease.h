#ifndef MEDANALYSIS_SERVER_DISEASE_H
#define MEDANALYSIS_SERVER_DISEASE_H
#include <iostream>
#include <vector>

class Disease {
 public:
  //////constructor///////
  Disease(std::string cs, std::vector<std::string> li);

  //////getter and setter//////

  const std::string &name() const;
  const std::vector<std::string> &riskfulGenes() const;

  //////destructor//////
  virtual ~Disease();
 private:
  std::string p_name;
  std::vector<std::string> p_list;

};

#endif //MEDANALYSIS_SERVER_DISEASE_H
