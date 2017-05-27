#include <catch.hpp>
#include <utils/utils.h>

using Catch::Matchers::Vector::ContainsElementMatcher;


TEST_CASE("Server Utils", "[utils][server]") {
    std::string line = "Line:to::parse:";

    std::vector<std::string> parts = split(line, ':');

    REQUIRE(parts.at(0) == "Line");
    REQUIRE(parts.at(1) == "to");
    REQUIRE(parts.at(2) == "");
    REQUIRE(parts.at(3) == "parse");
}