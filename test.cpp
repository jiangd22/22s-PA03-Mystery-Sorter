//
// Created by David Jiang on 2/8/22.
//

#include "catch.hpp"
#include "DSString.h"

//#include <cstring>

using namespace std;
//Example code:
//    TEST_CASE("Location Message", “[ClassBeingTested]”)
//    {
//        SECTION("Message describing what is being tested at this point" ) {
//            REQUIRE(Boolean assertion);
//        }
//    }

TEST_CASE(" DSString.csv, [DSString]")
{
    DSString word1 = "Ash Blossom & Joyous Spring";
    DSString word2 = "MAXX C";
    char* text1 = "Ash Blossom & Joyous Spring";
    char* text2 = "MAXX C";


    SECTION("overload Assignment Operators &DSString") {
        DSString testcase1 = word1;
        DSString testcase2 = testcase1;
        DSString testcase3 = word2;

        REQUIRE((word1 == "Ash Blossom & Joyous Spring") == true);
        REQUIRE((testcase1 == "Ash Blossom & Joyous Spring") == true);
        REQUIRE((testcase2 == "Ash Blossom & Joyous Spring") == true);
        REQUIRE((testcase3 == "MAXX C") == true);
    }

    SECTION("Overloaded Assignment Operators char*"){
        char* testcase1 = text1;
        char* testcase2 = testcase1;
        char* testcase3 = text2;

        REQUIRE((text1 == "Ash Blossom & Joyous Spring") == true);
        REQUIRE((testcase1 == "Ash Blossom & Joyous Spring") == true);
        REQUIRE((testcase2 == "Ash Blossom & Joyous Spring") == true);
        REQUIRE((testcase3 == "MAXX C") == true);

    }

    SECTION("compare two String, DSString and Char*"){
        REQUIRE((word1 > word2) == false);
        REQUIRE((word2 > word1) == true);
        REQUIRE((text1 > text2) == false);
        REQUIRE((text2 > text1) == true);
    }

    SECTION("compare two String, DSString and Char*"){
        REQUIRE((word1 > word2) == false);
        REQUIRE((word2 > word1) == true);
        REQUIRE((text1 > text2) == false);
        REQUIRE((text2 > text1) == true);
    }

    SECTION("Subscript operator"){
        REQUIRE((word1[7]) == 's');
        REQUIRE((word1[19]) == 's');
        REQUIRE((word2[3]) == 'X');
        REQUIRE((word2[4]) == ' ');
    }

    SECTION("substring"){
        REQUIRE(((word1.substring(0,3)) == "Ash")== true);
        REQUIRE(((word1.substring(4,7)) == "Blossom") == true);
        REQUIRE(((word2.substring(0,4)) == "MAXX") == true);
        REQUIRE(((word2.substring(5,1)) == "C") == true);
    }

    SECTION("Find Length of the word" ) {

        REQUIRE(word1.getLength() == 27);
        REQUIRE(word2.getLength() == 6);

    }

    SECTION("Overloaded non-modifying string operator+ (const DSString&)"){
        DSString word11 = word1 + word1;
        DSString word22 = word2 + word2;


        REQUIRE(word11.getLength() == 54);
        REQUIRE(word22.getLength() == 12);

        REQUIRE((word11 == "Ash Blossom & Joyous SpringAsh Blossom & Joyous Spring") == true);
        REQUIRE((word22 == "MAXX CMAXX C") == true);
    }

}


