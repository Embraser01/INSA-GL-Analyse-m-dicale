#ifndef MEDANALYSIS_CLIENT_GENOME_H
#define MEDANALYSIS_CLIENT_GENOME_H

#include <string>
#include <vector>

class Genome {

public:

    const std::vector<std::string> &geneticCode() const;

    void addWord(std::string);

private:
    std::vector<std::string> p_geneticCode;
};

#endif //MEDANALYSIS_CLIENT_GENOME_H
