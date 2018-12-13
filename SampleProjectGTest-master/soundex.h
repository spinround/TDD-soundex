//
// Created by andrewyoung5 on 12/13/2018.
//

#ifndef FIRSTEXAMPLE_SOUNDEX_H
#define FIRSTEXAMPLE_SOUNDEX_H

#include <iostream>
#include <string>

using namespace std;
class Soundex
{
private:
    string zeroPad(const string& word)const;

public:
    string encode(const string& word) const;

};


#endif //FIRSTEXAMPLE_SOUNDEX_H
