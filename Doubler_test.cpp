#include <CppUTest/CommandLineTestRunner.h>

#include "Doubler.hpp"

TEST_GROUP(GroupDoubler) { };

TEST(GroupDoubler, Doubler_test1) 
{ 
    CHECK_EQUAL(doubler(21), 42);
}

TEST(GroupDoubler, Doubler_test2) 
{
    CHECK_EQUAL(doubler(0), 0);
}

