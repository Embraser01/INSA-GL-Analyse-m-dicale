#include "OneController.h"
#include "../services/AnalysisService.h"

vector<string> OneController::doOneEvaluation(vector<string> req,const string filePath) {
  
    // TODO Parsing pour evaluation d'une maladie (récupérer la maladie, etc...)
    string diseaseName = req[2];
    vector<string> genes = split(req[3], ';', false);
    const char * allowed = "ATCG";
    if(!check_char_presence(genes,allowed)){
        return getError("Unauthorized character found in the genetic code, aborting analysis");
    }
    AnalysisService services = AnalysisService(filePath);
    auto disease = services.getDiseaseByName(diseaseName);
    Genome genome = Genome(genes);
    bool risk = false;
    bool error = true;
    for (auto it = disease.first; it != disease.second; ++it) {
        error = false;
        if (services.evaluateOne(genome, it->second)) {
            risk = true;
        }
    }
    if (error) {
        return getError("Unknown disease to the database");
    }

    vector<string> response;
    response.push_back("MA v1.0");
    response.push_back("DISEASE "+diseaseName);
    if(risk){
        response.push_back("1");
        response.push_back("");
        return response;
    }
    response.push_back("0");
    response.push_back("");
    return response;
}
