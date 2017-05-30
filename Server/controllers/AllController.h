#ifndef MEDANALYSIS_SERVER_ALLCONTROLLER_H
#define MEDANALYSIS_SERVER_ALLCONTROLLER_H

#include <iostream>
#include <string>
#include <vector>
#include "../services/AnalysisService.h"
#include "../models/Genome.h"
#include "../utils/utils.h"

using std::istream;
using std::string;
using std::vector;

class AllController {
public:

    AllController(string filePath);

    vector<string> doCompleteEvaluation(vector<string> req);

private:
    AnalysisService service;

};

#endif //MEDANALYSIS_SERVER_ALLCONTROLLER_H
