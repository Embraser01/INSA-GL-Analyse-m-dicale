#ifndef MEDANALYSIS_CLIENT_COMMUNICATION_EXCEPTION_H
#define MEDANALYSIS_CLIENT_COMMUNICATION_EXCEPTION_H

#include <exception>

class CommunicationException :
    public std::exception {

 public:
  CommunicationException() {}
  virtual ~CommunicationException() {}
    const char *what() const noexcept {
        return "Probleme de communication avec le serveur";
    }
};


#endif // MEDANALYSIS_CLIENT_COMMUNICATION_EXCEPTION_H