#include "AllController.h"

const static char EOP = ';';
const static char *ALLOWED_CHAR = "ATCG";

vector<string> AllController::doCompleteEvaluation(vector<string> req) {
    // TODO Parsing de la requête
    // TODO Check génome format

    string word_list = req[2];

    vector<string> res;
    vector<string> genes = split(word_list, EOP, true);
    int i = 0;

    if (!check_char_presence(genes, ALLOWED_CHAR)) {
        return getError("Unauthorized character found in the genetic code, aborting analysis");
    }
    res.push_back("MA v1.0");
    Genome genome = Genome(genes);
    vector<Disease> diseases = service.evaluateAll(genome);
    for (i = 0; i < diseases.size(); i++) {
        res.push_back("DISEASE " + diseases[i].name());
    }
    sort(res.begin()+2,res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    res.push_back("");

    return res;
}

AllController::AllController(string filePath) {

    service = AnalysisService(filePath);
}
