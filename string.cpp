#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>
TEST_CASE("empty string", "[string]") {
    std::string str;
    REQUIRE(str.empty());
}

using Catch::Matchers::Equals;
TEST_CASE("Initialize by char with number", "[string]") {
    std::string str(10, 'a');
    REQUIRE_THAT(str, Equals("aaaaaaaaaa"));
}

TEST_CASE("Initialize by string", "[string]") {
    std::string str("abc");
    REQUIRE_THAT(str, Equals("abc"));
}

TEST_CASE("Initialize by pointer", "[string]") {
    const char *data = "hoge";
    std::string str(data);
    REQUIRE_THAT(str, Equals("hoge"));
}

TEST_CASE("Initalize by char string", "[string]") {
    char org_str[] = {'4', '5', '6'};
    std::string str(org_str, std::end(org_str));
    REQUIRE_THAT(str, Equals("456"));
}

TEST_CASE("Initialize by literal", "[string]") {
    const char *org_str = "123456";
    std::string str(org_str+2, org_str+4);
    REQUIRE_THAT(str, Equals("34"));
}

TEST_CASE("Initalize by copy constructor", "[string]") {
    std::string org("123");
    std::string x(org);

    REQUIRE_THAT(org,Equals(x));
}