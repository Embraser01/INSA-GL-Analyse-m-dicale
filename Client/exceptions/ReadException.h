#ifndef MEDANALYSIS_CLIENT_READ_EXCEPTION_H
#define MEDANALYSIS_CLIENT_READ_EXCEPTION_H

#include <exception>

class ReadException :
		public std::exception {

 public:
  ReadException() {}
  virtual ~ReadException() {}
    const char *what() const noexcept {
        return "Impossible de lire le genome. Verifiez la presence du fichier ou son format";
    }
};

#endif // MEDANALYSIS_CLIENT_READ_EXCEPTION_H