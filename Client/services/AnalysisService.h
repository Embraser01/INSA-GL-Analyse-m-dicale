#ifndef MEDANALYSIS_CLIENT_ANALYSISSERVICE_H
#define MEDANALYSIS_CLIENT_ANALYSISSERVICE_H

#include <vector>
#include <string>
#include <algorithm>
#include "../models/Disease.h"
#include "../models/Genome.h"
#include "ServerService.h"

using std::vector;
using std::string;
using std::pair;


class AnalysisService {

public:

    AnalysisService(string filePath);

    vector<Disease> evaluateAll(Genome &g);

    vector<Disease> getDiseases() const;

    bool evaluateOne(Genome &g, Disease &d) const;

private:
    ServerService serverService;

};

#endif //MEDANALYSIS_CLIENT_ANALYSISSERVICE_H
