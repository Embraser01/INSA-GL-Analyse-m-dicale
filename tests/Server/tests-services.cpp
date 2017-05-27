#include <catch.hpp>
#include <models/Genome.h>
#include <services/AnalysisService.h>

TEST_CASE("Evaluating All Diseases", "[server][service]") {
    AnalysisService service = AnalysisService("./res/disease");
    vector<string> genes;
    genes.push_back("GTAC");
    genes.push_back("GGCC");
    Genome genome = Genome(genes);
    vector<Disease> diseases = service.evaluateAll(genome);
    REQUIRE(diseases[0].name() == "Cancer");
}

TEST_CASE("Evaluating One Disease", "[server][service]") {
    AnalysisService service = AnalysisService("./res/disease");
    vector<string> genes;
    genes.push_back("GTAC");
    genes.push_back("GGCC");
    Disease disease = Disease("Cancer", genes);
    Genome genome = Genome(genes);
    REQUIRE(service.evaluateOne(genome, disease));
}

TEST_CASE("Getting disease by name", "[server][service]") {
    AnalysisService service = AnalysisService("./res/disease");
    pair<unordered_multimap<string, Disease>::iterator,
            unordered_multimap<string, Disease>::iterator
    > disease = service.getDiseaseByName("Cancer");
    REQUIRE(disease.first->first == "Cancer");
    REQUIRE(disease.first->second.name() == "Cancer");
    REQUIRE(disease.first->second.riskfulGenes()[0] == "GTAC");
    REQUIRE(disease.first->second.riskfulGenes()[1] == "GGCC");
}

TEST_CASE("Getting diseases", "[server][service]") {
    AnalysisService service = AnalysisService("./res/disease");
    auto diseasesMap = service.getDiseases();
    unordered_multimap<std::string, Disease>::iterator iter;
    vector<string> diseases;
    //diseases on the iterator qre on the opposite order
    diseases.push_back("YYDSB");
    diseases.push_back("YYSB");
    diseases.push_back("Cancer");

    int i = 0;
    for (iter = diseasesMap.begin(); iter != diseasesMap.end(); iter++) {
        REQUIRE(iter->first == diseases[i]);
        i++;
    }
}