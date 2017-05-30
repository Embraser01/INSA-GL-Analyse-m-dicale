#ifndef MEDANALYSIS_CLIENT_SERVER_H
#define MEDANALYSIS_CLIENT_SERVER_H

#include <string>

class Server {

 public:

  Server ();
  Server (const std::string &p_address, const std::string &p_name);

  const std::string &name () const;
  const std::string &address () const;

  void setAddress (const std::string &p_address);
  void setName (const std::string &p_name);

 private:
  std::string p_address;
  std::string p_name;
};

#endif //MEDANALYSIS_CLIENT_SERVER_H
