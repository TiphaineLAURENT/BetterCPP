//
// Created by tiphaine on 03/04/19.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../src/type/type.hpp"

TEST_CASE("Values computation", "[value]") {
        auto v = Value<int>{};
        REQUIRE(v.getValue() == 0);

        SECTION("Assigning value with copy assignment operator") {
                v = 5;
                REQUIRE(v.getValue() == 5);
        }

        SECTION("Assigning value with move assignment operator") {
                v = std::move(5);
                REQUIRE(v.getValue() == 5);
        }

        SECTION("Creating string from value") {
                REQUIRE(v.toString() == std::to_string(0));
        }

        SECTION("Comparing Values") {
                auto v2 = Value<int>{42};
                auto v3 = Value<int>{-42};

                REQUIRE(v == v);
                REQUIRE(v != v2);

                REQUIRE(v < v2);
                REQUIRE(v > v3);

                REQUIRE(v <= v2);
                REQUIRE(v >= v3);
        }

        SECTION("Comparing value with T") {
                REQUIRE(v == 0);
                REQUIRE(v != 42);

                REQUIRE(v < 42);
                REQUIRE(v > -42);

                REQUIRE(v <= 42);
                REQUIRE(v >= -42);
        }

        SECTION("Doing math assignment on Values") {
                auto v2 = Value<int>{42};
                auto ref = int{0};

                v += v2;
                ref += v2.getValue();
                REQUIRE(v == ref);

                v -= v2;
                ref -= v2.getValue();
                REQUIRE(v == ref);

                v *= v2;
                ref *= v2.getValue();
                REQUIRE(v == ref);

                v /= v2;
                ref /= v2.getValue();
                REQUIRE(v == ref);
        }

        SECTION("Doing math assignment on value with T") {
                auto ref = int{0};

                v += 42;
                ref += 42;
                REQUIRE(v == ref);

                v -= 42;
                ref -= 42;
                REQUIRE(v == ref);

                v *= 42;
                ref *= 42;
                REQUIRE(v == ref);

                v /= 42;
                ref /= 42;
                REQUIRE(v == ref);
        }
}