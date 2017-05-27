#ifndef MEDANALYSIS_SERVER_DISEASEDAO_H
#define MEDANALYSIS_SERVER_DISEASEDAO_H

#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include "../models/Disease.h"
#include "../utils/utils.h"
#include "../exceptions/DiseaseNotFoundException.h"
#include "../exceptions/ReadException.h"

using std::string;
using std::unordered_multimap;
using std::pair;
using std::vector;
using std::ifstream;

class DiseaseDAO {
public:
    DiseaseDAO(string fileName = "Diseases.txt");

    ~DiseaseDAO();

    const unordered_multimap<string, Disease> findAll();

    const pair<
            unordered_multimap<string, Disease>::iterator,
            unordered_multimap<string, Disease>::iterator
    > findByName(const string basic_string);

private:
    string name;
    unordered_multimap<string, Disease> diseases;
};

#endif //MEDANALYSIS_SERVER_DISEASEDAO_H
