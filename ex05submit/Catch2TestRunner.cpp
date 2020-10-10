#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "CircleList.h"


using namespace ds_course;
TEST_CASE("circlelists insert stuff in reverse order", "[circlelist]")
{
    CircleList cL;
    REQUIRE(cL.to_str() == "");
    cL.add(2);
    REQUIRE(cL.getSize() == 1);
    REQUIRE(cL.to_str() == "2");
    cL.add(4);
    REQUIRE(cL.getSize() == 2);
    REQUIRE(cL.to_str() == "4 2");
    cL.add(6);
    REQUIRE(cL.getSize() == 3);
    REQUIRE(cL.to_str() == "6 4 2");
}

TEST_CASE("On 6-number list:", "[circlelist]")
{
    CircleList cl;
    cl.add(11);
    cl.advance();
    cl.add(12);
    cl.advance();
    cl.add(13);
    cl.advance();
    cl.add(14);
    cl.advance();
    cl.add(15);
    cl.advance();
    cl.add(16);
    cl.advance();
    REQUIRE(cl.to_str() == "11 12 13 14 15 16");

    SECTION("Can advance 4 times") {
        for (int j = 0; j < 4; j++) 
            cl.advance();
        REQUIRE(cl.to_str() == "15 16 11 12 13 14");
    }

    SECTION("Insert at position 2") {
        cl.advance();
        cl.advance();
        REQUIRE(cl.to_str() == "13 14 15 16 11 12");
        cl.add(1000);
        REQUIRE(cl.to_str() == "1000 13 14 15 16 11 12");
        cl.advance();
        cl.advance();
        cl.advance();
        cl.advance();
        cl.advance();
        REQUIRE(cl.to_str() == "11 12 1000 13 14 15 16");
    }

    SECTION("Delete at position 2") {
        cl.advance();
        cl.advance();
        REQUIRE(cl.to_str() == "13 14 15 16 11 12");
        cl.remove();
        REQUIRE(cl.to_str() == "14 15 16 11 12");
        cl.advance();
        cl.advance();
        cl.advance();
        REQUIRE(cl.to_str() == "11 12 14 15 16");
    }

    SECTION("insert, then delete") {
        cl.add(100);
        REQUIRE(cl.to_str() == "100 11 12 13 14 15 16");
        cl.advance();
        cl.advance();
        cl.remove();
        cl.advance();
        cl.advance();
        cl.advance();
        cl.advance();
        REQUIRE(cl.to_str() == "100 11 13 14 15 16");
    }

    SECTION("ability to delete everything")
    {
        cl.remove();
        cl.remove();
        cl.remove();
        REQUIRE(cl.to_str() == "14 15 16");
        cl.advance();
        cl.remove();
        cl.remove();
        cl.remove();
        REQUIRE(cl.to_str() == "");
        cl.add(17);
        REQUIRE(cl.to_str() == "17");
    }
}
