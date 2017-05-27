#ifndef MEDANALYSIS_SERVER_ANALYSISEXCEPTION_H
#define MEDANALYSIS_SERVER_ANALYSISEXCEPTION_H

#include <exception>

class AnalysisException :
        public std::exception {

public:
    AnalysisException() {}

    virtual ~AnalysisException() {}

    const char *what() const noexcept {
        return "Erreur lors de l'analyse du génome";
    }
};

#endif //MEDANALYSIS_SERVER_ANALYSISEXCEPTION_H
