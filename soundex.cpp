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
        auto zerosNeeded = MaxCodeLength-word.length();
        return word + string(zerosNeeded,'0');
    }
    /**
     * @brief encode word
     * @param word
     * @return encoded word
     */
string Soundex::encode(const string& word) const
{



    return zeroPad(toUpper(head(word)) + (encodeDigits(tail(word))));
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
//    if(word.empty())
//    {
//        return "";
//    }
    string encoding;
    for(auto letter : word)
    {
        if(isComplete(encoding))
        {
            break;
        }
        else if(encodeDigit(letter) != lastDigit(encoding))
        {
            encoding += encodeDigit(letter);
        }
    }
    return encoding;
}


/**
 * @brief encode single digit
 * @param word
 * @return encoded digit
 */
string Soundex::encodeDigit(char letter) const
{
    const unordered_map<char,string> encoding
    {
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

    auto it = encoding.find(letter);

    // if you reach the end of the map, you got no match. Return empty.
    return it == encoding.end() ? "" : it->second;


}

bool Soundex::isComplete(const string &encoding) const
{
    return encoding.length() == MaxCodeLength -1;
}

string Soundex::tail(const string &word) const
{
    return word.substr(1);
}

string Soundex::lastDigit(const string &encoding) const
{
    if(encoding.empty())
    {
        return "";
    }
    else
    {
        return std::string( 1 , encoding.back());
    }


}

string Soundex::toUpper(const string &word) const {
    return std::string(1, toupper(static_cast<unsigned char>(word.front())));
}





