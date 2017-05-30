#include "Genome.h"


const std::vector<std::string> &Genome::geneticCode() const {
    return p_geneticCode;
}

void Genome::addWord(std::string word) {
    p_geneticCode.push_back(word);
}
