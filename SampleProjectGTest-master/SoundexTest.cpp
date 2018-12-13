#include "gmock/gmock.h"


#include <iostream>
#include <string>

using namespace std;

class Soundex
{
    /**
     * @brief pads with zeros
     * @param word
     * @return padded word
     */
    string zeroPad(const string& word)const
    {
       return word +"000";
    }
    public:
    /**
     * @brief encode word
     * @param word
     * @return encoded word
     */
      string encode(const string& word) const
      {
         return zeroPad(word);
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
   ASSERT_THAT(encode, Eq("A000"));
}

TEST(SoundexEncoding, padsWithZerosToEnsureThreeDigits)
{
   //arrange
   Soundex soundex;
   //act
   auto encode = soundex.encode("I");
   //assert
   ASSERT_THAT(encode, Eq("I000"));
}
