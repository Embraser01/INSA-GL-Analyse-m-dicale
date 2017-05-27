#include <catch.hpp>
#include <utils/utils.h>
#include <controllers/ListController.h>
#include <controllers/OneController.h>
#include <controllers/AllController.h>

using Catch::Matchers::Vector::ContainsElementMatcher;
using std::string;
using std::vector;

TEST_CASE("List Controller", "[controller][server]") {
    vector<string> str;
    vector<string> input;
    input.push_back("MA v1.0");
    input.push_back("GET DISEASES");
    input.push_back("");

    str = ListController("./res/dictionnaire").doGetList(input);
    REQUIRE(str[0] == "MA v1.0");
    REQUIRE(str[1] == "DISEASES");
    //REQUIRE(str[2]=="");
    REQUIRE(str[2] == "Cancer");
    REQUIRE(str[3] == "Con");
    REQUIRE(str[4] == "Petitbite");
    REQUIRE(str[5] == "");
}

TEST_CASE("One Controller", "[controller][server]") {
    vector<string> str;
    vector<string> input;
    input.push_back("MA v1.0");
    input.push_back("CHECK DISEASES");
    input.push_back("Cancer");
    input.push_back("CCCC;TATA");
    input.push_back("");
    str = OneController().doOneEvaluation(input, "./res/dictionnaire");
    REQUIRE(str[0] == "MA v1.0");
    REQUIRE(str[1] == "DISEASE Cancer");
    //REQUIRE(str[2]=="");
    REQUIRE(str[2] == "1");
    REQUIRE(str[3] == "");
}

TEST_CASE("All Controller", "[controller][server]") {
    vector<string> str;
    vector<string> input;
    input.push_back("MA v1.0");
    input.push_back("CHECK ALL");
    input.push_back("CCCC;TATA;TTAA");
    //input.push_back("TATA");
    //input.push_back("");
    str = AllController("./res/dictionnaire").doCompleteEvaluation(input);
    REQUIRE(str[0] == "MA v1.0");
    REQUIRE(str[1] == "DISEASE Cancer");

    REQUIRE(str[2] == "");
}