#include <catch.hpp>
#include <utils/utils.h>
#include <controllers/ListController.h>
#include <controllers/OneController.h>
#include <controllers/AllController.h>

using Catch::Matchers::Vector::ContainsElementMatcher;
using std::string;
using std::vector;

TEST_CASE("List Controller", "[controller][server]") {
    // check whole request for a complete evaluation

    vector<string> str; // la reponse
    vector<string> input; // la requete
    input.push_back("MA v1.0");
    input.push_back("GET DISEASES");
    input.push_back("");

    str = ListController("./res/dico1.txt").doGetList(input);
    REQUIRE(str[0] == "MA v1.0");
    REQUIRE(str[1] == "DISEASES");
    REQUIRE(str[2] == "Cancer");
    REQUIRE(str[3] == "Disease007");
    REQUIRE(str[4] == "Disease117");
    REQUIRE(str[5] == "");
}

TEST_CASE("One Controller", "[controller][server]") {
    vector<string> str;
    vector<string> input;
    input.push_back("MA v1.0");
    input.push_back("CHECK DISEASES"); // DISEASE\r\nDisease117\r\nACAC;ATA;AAAA;TATA;A\r\n\r\n
    input.push_back("Disease117");
    input.push_back("ACAC;ATA;AAAA;TATA;A");
    input.push_back("");
    str = OneController().doOneEvaluation(input, "./res/dico1.txt");
    REQUIRE(str[0] == "MA v1.0");
    REQUIRE(str[1] == "DISEASE Disease117");
    REQUIRE(str[2] == "1");
    REQUIRE(str[3] == "");
}

TEST_CASE("All Controller", "[controller][server]") {
    vector<string> str;
    vector<string> input;
    input.push_back("MA v1.0");
    input.push_back("CHECK ALL");
    input.push_back("ACAC;ATA;AAAA;TATA;A");
    input.push_back("");
    str = AllController("./res/dico1.txt").doCompleteEvaluation(input);
    REQUIRE(str[0] == "MA v1.0");
    REQUIRE(str[1] == "DISEASE Disease117");
    REQUIRE(str[2] == "");
}