#include "Genome.h"

Genome::Genome() {

}

Genome::Genome(std::vector<std::string> &genes) {
    geneticCode = genes;
}

Genome::~Genome() {

}

const std::vector<std::string> &Genome::getGene() const {
    return geneticCode;
}
