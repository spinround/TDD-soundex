#include "gmock/gmock.h"
#include "Soundex.h"


using ::testing::Eq;
//create a class fixture
class SoundexEncoding: public testing::Test
{
public:
    Soundex soundex;
};
TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
   //arrange
   //act
   //assert

   ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, padsWithZerosToEnsureThreeDigits)
{
   //arrange
   //act
   //assert
   ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplaceConsonanatsWithAppropriateDigits)
{
    //arrange
    //act
    //assert
    ASSERT_THAT(soundex.encode("Ab"), Eq("A100"));
    ASSERT_THAT(soundex.encode("Ac"), Eq("A200"));
    ASSERT_THAT(soundex.encode("Ad"), Eq("A300"));
    ASSERT_THAT(soundex.encode("Al"), Eq("A400"));
    ASSERT_THAT(soundex.encode("Am"), Eq("A500"));
    ASSERT_THAT(soundex.encode("Ar"), Eq("A600"));
}
