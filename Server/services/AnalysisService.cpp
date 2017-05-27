#include "AnalysisService.h"

vector<Disease> AnalysisService::evaluateAll(Genome &g) {
    auto diseases = diseaseDAO.findAll();
    vector<Disease> checkDiseases;

    for (auto diseases_it = diseases.begin(); diseases_it != diseases.end(); diseases_it++) {

        if (evaluateOne(g, diseases_it->second)) {
            checkDiseases.push_back(diseases_it->second);
        }
    }
    return checkDiseases;
}

unordered_multimap<string, Disease> AnalysisService::getDiseases() {
    try {
        return diseaseDAO.findAll();
    } catch (std::exception exception) {
        throw AnalysisException();
    }
}

const pair<
        unordered_multimap<string, Disease>::iterator,
        unordered_multimap<string, Disease>::iterator
> AnalysisService::getDiseaseByName(string name) {
    try {
        return diseaseDAO.findByName(name);
    } catch (std::exception exception) {
        throw AnalysisException();
    }
}


bool AnalysisService::evaluateOne(Genome &g, Disease &d) const {
    auto words = d.riskfulGenes();
    auto gene = g.getGene();
    vector<string>::iterator words_it;
    vector<string>::iterator g_it;

    for (words_it = words.begin(); words_it < words.end(); words_it++) {
        // Pour chaque gene de la maladie, on cherche dans le Genome

        if (std::find(gene.begin(), gene.end(), *words_it) == gene.end()) {
            return false;
        }
    }
    return true;
}

AnalysisService::AnalysisService() {
    diseaseDAO = DiseaseDAO(/* TODO Get path argument */);
}

AnalysisService::AnalysisService(const string filePath) {
    diseaseDAO = DiseaseDAO(filePath);
}


