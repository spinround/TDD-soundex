//
// Created by andrewyoung5 on 12/18/2018.
//

#include <gmock/gmock.h>

using namespace testing;
class Adder{
public:
    static int sum(int a, int b)
    {
        return a+b;
    }
};

struct SumCase
{
    int a,b,expected;
    SumCase(int anA, int aB, int anExpected)
    :a(anA), b(aB), expected(anExpected){}
};

class anAdder: public TestWithParam<SumCase>
{};

TEST_P(anAdder, gerateLotsOfSums)
{
    SumCase input = GetParam();
    ASSERT_THAT(Adder::sum(input.a,input.b), Eq(input.expected));
}

SumCase sums [] ={};