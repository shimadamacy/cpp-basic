#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>
TEST_CASE("empty string", "[string]") {
    std::string str;
    REQUIRE(str.empty());
}

using Catch::Matchers::Equals;
TEST_CASE("Initialize string", "[string]") {
    std::string str(10, 'a');
    REQUIRE_THAT(str, Equals("aaaaaaaaaa"));
}
