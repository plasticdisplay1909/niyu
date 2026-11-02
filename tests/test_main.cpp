#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "niyu/compiler.hpp"

TEST_CASE("Compiler version") {
    REQUIRE(niyu::version() == "Niyu 0.1.0");
}