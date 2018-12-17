#include "gmock/gmock.h"
#include "Soundex.h"


using namespace testing;
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

TEST_F(SoundexEncoding, ignoreNonAlphabetics)
{
    //arrange
    //act
    //assert
    ASSERT_THAT(soundex.encode("A#"),Eq("A000"));
}

TEST_F(SoundexEncoding, extraAEIOEct)
{
    //arrange
    //act
    //assert
    ASSERT_THAT(soundex.encode("Aaio"),Eq("A000"));
}

TEST_F(SoundexEncoding, ReplaceMultipleConsonantsWithDigits)
{
    // Arrange @ class fixture
    // Act & Assert
    ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}

TEST_F(SoundexEncoding, LimitLengthToFourCharacters)
{
    // Arrange @ class fixture
    // Act & Assert
    ASSERT_THAT(soundex.encode("Dcdlb").length(), Eq(4u));
}

TEST_F(SoundexEncoding, CombineDuplicateEncoding)
{
    // Arrange @ class fixture
    // Act & Assert
    ASSERT_THAT(soundex.encodeDigit('b'), Eq(soundex.encodeDigit('f')));
    ASSERT_THAT(soundex.encodeDigit('x'), Eq(soundex.encodeDigit('g')));
    ASSERT_THAT(soundex.encodeDigit('d'), Eq(soundex.encodeDigit('t')));

    ASSERT_THAT(soundex.encode("Abfxgdt"), Eq("A123"));
}

TEST_F(SoundexEncoding, uppercase)
{
    // Arrange @ class fixture
    // Act & Assert
    ASSERT_THAT(soundex.encode("abcd"), StartsWith("A"));
}

TEST_F(SoundexEncoding, ignoreVowelsAndSuch)
{
    //arrange
    //act
    //assert
    ASSERT_THAT(soundex.encode("BaAeEiIoOuUhHwWyYcdl"),Eq("B234"));
}

TEST_F(SoundexEncoding, yah)
{
    //arrange
    //act
    //assert
    ASSERT_THAT(soundex.encode("BCDL"),Eq(soundex.encode("Bcdl")));
}

TEST_F(SoundexEncoding, honeyman)
{
    //arrange
    //act
    //assert
    ASSERT_THAT(soundex.encode("honeyman"),Eq(soundex.encode("H555")));
}