#include "gmock/gmock.h"


#include <iostream>
#include <string>

using namespace std;

class Soundex
{
    public:
      string encode(const string& word) const
      {
         return word;
      }
};
using ::testing::Eq;
TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
   //arrange
   Soundex soundex;
   //act
   auto encode = soundex.encode("A");
   //assert
   ASSERT_THAT(encode, Eq("A"));
}

