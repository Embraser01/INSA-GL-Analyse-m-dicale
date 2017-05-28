#include <models/Server.h>
#include <catch/catch.hpp>


TEST_CASE("Server model", "[models]") {

    Server server("127.0.0.1", "Mon super serveur");

    REQUIRE(server.address() == "127.0.0.1");
    REQUIRE(server.name() == "Mon super serveur");
}