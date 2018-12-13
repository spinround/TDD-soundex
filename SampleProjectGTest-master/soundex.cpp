//
// Created by andrewyoung5 on 12/13/2018.
//

#include "soundex.h"
#include <iostream>
#include <string>

    /**
     * @brief pads with zeros
     * @param word
     * @return padded word
     */
string Soundex::zeroPad(const string& word)const
    {
        auto zerosNeeded = 4-word.length();
        return word + string(zerosNeeded,'0');
    }
    /**
     * @brief encode word
     * @param word
     * @return encoded word
     */
string Soundex::encode(const string& word) const
{

    return zeroPad(head(word)+encodeDigits(word));
}

/**
 * @brief extract first char of sting
 * @param word
 * @return first letter of string
 */
string Soundex::head(const string &word) const
{
    return word.substr(0,1);
}


/**
 * @brief encode the string into digits
 * @param word
 * @return encoded string
 */
string Soundex::encodeDigits(const string &word) const
{
    if(word.length()>1)
    {
        return "1";
    }

    return "";
}



