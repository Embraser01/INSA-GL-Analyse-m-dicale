#include <models/Disease.h>
#include <models/Genome.h>
#include <catch.hpp>


TEST_CASE("Genome model", "[models][server]") {

    Genome genome;
}

TEST_CASE("Disease model", "[models][server]") {

    Disease disease("Cancer", std::vector<std::string>());

    REQUIRE(disease.name() == "Cancer");
    REQUIRE(disease.riskfulGenes().empty());

    // TODO Test with not empty vector
}