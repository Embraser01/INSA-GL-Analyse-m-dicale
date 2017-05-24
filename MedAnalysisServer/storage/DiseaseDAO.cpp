#include "DiseaseDAO.h"

const static char DELIM = ';';
const static char *ALLOWED_CHAR = "ATCG";

DiseaseDAO::DiseaseDAO(string fileName) {
    name = fileName;
}

DiseaseDAO::~DiseaseDAO() {
}

const unordered_multimap<string, Disease> DiseaseDAO::findAll() {

    if (!diseases.empty()) {
        return diseases;
    }

    ifstream fin;
    fin.open(name);
    if (!fin.good() || fin.eof()) {
        throw ReadException();
        // TODO Exit Program
    }

    vector<string> linePart;
    string line;
    string diseaseName;

    //check if first line is like MA v1.0
    getline(fin, line);

    if (line.compare("MA v1.0")) {

        while (!fin.eof()) {
            getline(fin, line);
            linePart = split(line, DELIM, false);

            diseaseName = linePart.at(0);
            linePart.erase(linePart.begin());

            for (auto it = linePart.begin(); it != linePart.end(); it++) {
                if (it->find_first_not_of(ALLOWED_CHAR) != string::npos) {
                    throw ReadException();
                    // TODO Exit Program
                }
            }

            diseases.emplace(diseaseName, Disease(diseaseName, linePart));
        }

    } else {
        // TODO Exit Program
        throw ReadException();
    }

    return diseases;
}

const pair<
        unordered_multimap<string, Disease>::iterator,
        unordered_multimap<string, Disease>::iterator
> DiseaseDAO::findByName(const string basic_string) {

    try {
        findAll();
    } catch (ReadException &exception) {
        throw exception; // For upper levels
    }

    auto range = diseases.equal_range(basic_string);
    if (range.first == range.second) {
        throw DiseaseNotFoundException();
    }
    return range;
}
