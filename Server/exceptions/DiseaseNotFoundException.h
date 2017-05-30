#ifndef MEDANALYSIS_SERVER_DISEASENOTFOUNDEXCEPTION_H
#define MEDANALYSIS_SERVER_DISEASENOTFOUNDEXCEPTION_H

#include <exception>

class DiseaseNotFoundException :
        public std::exception {

public:
    DiseaseNotFoundException() {}

    virtual ~DiseaseNotFoundException() {}

    const char *what() const noexcept {
        return "La maladie envoyé n'existe pas sur ce serveur";
    }
};

#endif //MEDANALYSIS_SERVER_DISEASENOTFOUNDEXCEPTION_H
