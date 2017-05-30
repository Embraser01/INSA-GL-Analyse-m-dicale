#ifndef MEDANALYSIS_SERVER_READ_EXCEPTION_H
#define MEDANALYSIS_SERVER_READ_EXCEPTION_H

#include <exception>

class ReadException :
        public std::exception {

public:
    ReadException() {}

    virtual ~ReadException() {}

    const char *what() const noexcept {
        return "Erreur lors de la lecture du dictionnaire des maladies";
    }
};

#endif // MEDANALYSIS_SERVER_READ_EXCEPTION_H