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
    safeGetline(fin, line);

    if (line.compare("MA v1.0") == 0) {

        safeGetline(fin, line);
        while (!line.empty() && !fin.eof()) {

            linePart = split(line, DELIM, false);

            diseaseName = linePart.at(0);
            linePart.erase(linePart.begin());
            if (!check_char_presence(linePart, ALLOWED_CHAR)) {
                throw ReadException();
            }

            diseases.emplace(diseaseName, Disease(diseaseName, linePart));
            safeGetline(fin, line);
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
