#ifndef MEDANALYSIS_CLIENT_SERVICE_EXCEPTION_H
#define MEDANALYSIS_CLIENT_SERVICE_EXCEPTION_H

#include <exception>

class ServiceException :
		public std::exception {

 public:
  ServiceException() {}
  virtual ~ServiceException() {}
    const char *what() const noexcept {
        return "Une erreur s'est produite dans le service de gestion des serveurs.";
    }
};

#endif // MEDANALYSIS_CLIENT_SERVICE_EXCEPTION_H