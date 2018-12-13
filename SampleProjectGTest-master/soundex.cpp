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
        return word +"000";
    }
    /**
     * @brief encode word
     * @param word
     * @return encoded word
     */
    string Soundex::encode(const string& word) const
    {
        return zeroPad(word);
    }



