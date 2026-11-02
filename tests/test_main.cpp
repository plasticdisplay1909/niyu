#include <catch2/catch_test_macros.hpp>

#include "niyu/compiler.hpp"

TEST_CASE("Compiler version") {
    REQUIRE(niyu::version() == "Niyu 0.1.0");
}