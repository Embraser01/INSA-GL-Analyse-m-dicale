#ifndef MEDANALYSIS_SERVER_GENOME_H
#define MEDANALYSIS_SERVER_GENOME_H

#include <string>
#include <vector>

class Genome {
public:
    Genome();

    Genome(std::vector<std::string> &genes);

    virtual ~Genome();

    const std::vector<std::string> &getGene() const;

private:
    std::vector<std::string> geneticCode;
};

#endif //MEDANALYSIS_SERVER_GENOME_H
