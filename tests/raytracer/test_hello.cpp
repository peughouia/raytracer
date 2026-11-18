#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "raytracer/hello.hpp"

TEST_CASE("Greeting function behaves as expected", "[greeting]") {
    SECTION("Default greeting targets World") {
        std::string result = raytracer::get_greeting();
        REQUIRE(result == "Hello, World! Welcome to the Raytracer project.");
    }

    SECTION("Custom greeting targets specific recipient") {
        std::string result = raytracer::get_greeting("Alice");
        REQUIRE(result == "Hello, Alice! Welcome to the Raytracer project.");
    }
}

TEST_CASE("Project info contains essential version metadata", "[info]") {
    std::string info = raytracer::get_project_info();
    REQUIRE_FALSE(info.empty());
    CHECK(info.find("Raytracer v0.1.0") != std::string::npos);
    CHECK(info.find("C++20") != std::string::npos);
}

SCENARIO("Basic vector arithmetic for 3D raytracing (TDD Showcase)", "[math][vec3]") {
    GIVEN("Two 3D vectors") {
        raytracer::Vec3 a{1.0, 2.0, 3.0};
        raytracer::Vec3 b{4.0, 5.0, 6.0};

        WHEN("They are added together") {
            raytracer::Vec3 sum = a + b;

            THEN("The components are added element-wise") {
                REQUIRE(sum.x == Catch::Approx(5.0));
                REQUIRE(sum.y == Catch::Approx(7.0));
                REQUIRE(sum.z == Catch::Approx(9.0));
            }
        }

        WHEN("They are subtracted") {
            raytracer::Vec3 diff = b - a;

            THEN("The difference matches element-wise subtraction") {
                REQUIRE(diff.x == Catch::Approx(3.0));
                REQUIRE(diff.y == Catch::Approx(3.0));
                REQUIRE(diff.z == Catch::Approx(3.0));
            }
        }

        WHEN("Scaled by a scalar") {
            raytracer::Vec3 scaled = a * 2.5;

            THEN("Each component is multiplied by the scalar") {
                REQUIRE(scaled.x == Catch::Approx(2.5));
                REQUIRE(scaled.y == Catch::Approx(5.0));
                REQUIRE(scaled.z == Catch::Approx(7.5));
            }
        }

        WHEN("Calculating dot product") {
            double dot = a.dot(b);

            THEN("The result is the sum of products (1*4 + 2*5 + 3*6 = 32)") {
                REQUIRE(dot == Catch::Approx(32.0));
            }
        }
    }
}
