#include "AnalysisService.h"

vector<Disease> AnalysisService::evaluateAll(Genome &g) {
    // TODO Request to each server
    return vector<Disease>();
}

vector<Disease> AnalysisService::getDiseases() const {
    // TODO Request to each server
    return vector<Disease>();
}


bool AnalysisService::evaluateOne(Genome &g, Disease &d) const {
    // TODO Request to each server
    return false;
}

AnalysisService::AnalysisService(string filePath) : serverService(ServerService(filePath)) {}
