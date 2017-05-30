#ifndef MEDANALYSIS_SERVER_ANALYSISSERVICE_H
#define MEDANALYSIS_SERVER_ANALYSISSERVICE_H

#include <vector>
#include <string>
#include <algorithm>
#include "../models/Disease.h"
#include "../models/Genome.h"
#include "../storage/DiseaseDAO.h"
#include "../exceptions/AnalysisException.h"

using std::vector;
using std::string;
using std::unordered_multimap;
using std::pair;


class AnalysisService {

public:

    AnalysisService();

    AnalysisService(const string filePath);

    vector<Disease> evaluateAll(Genome &g);

    unordered_multimap<string, Disease> getDiseases();

    const pair<
            unordered_multimap<string, Disease>::iterator,
            unordered_multimap<string, Disease>::iterator
    >  getDiseaseByName(string name);

    bool evaluateOne(Genome &g, Disease &d) const;

private:
    DiseaseDAO diseaseDAO;

};

#endif //MEDANALYSIS_SERVER_ANALYSISSERVICE_H
