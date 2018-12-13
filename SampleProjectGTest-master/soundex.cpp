//
// Created by andrewyoung5 on 12/13/2018.
//

#include "soundex.h"
#include <iostream>
#include <string>
#include <unordered_map>

    /**
     * @brief pads with zeros
     * @param word
     * @return padded word
     */
string Soundex::zeroPad(const string& word)const
    {
        auto zerosNeeded = MaxCodLength-word.length();
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
        return encodeDigit(word[1]);
    }

    return "";
}


/**
 * @brief encode single digit
 * @param word
 * @return encoded digit
 */
string Soundex::encodeDigit(char letter) const
{
    const unordered_map<char,string> encoding{
            {'b',"1"},
            {'f',"1"},
            {'p',"1"},
            {'v',"1"},
            {'g',"2"},
            {'j',"2"},
            {'k',"2"},
            {'q',"2"},
            {'s',"2"},
            {'x',"2"},
            {'z',"2"},
            {'t',"3"},
            {'l',"4"},
            {'m',"5"},
            {'n',"5"},
            {'r',"6"},
            {'c', "2"},
            {'d', "3"}
    };

    return encoding.find(letter)->second;


}



