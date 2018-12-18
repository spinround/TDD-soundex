//
// Created by andrewyoung5 on 12/17/2018.
//

#ifndef FIRSTEXAMPLE_TWEET_H
#define FIRSTEXAMPLE_TWEET_H
#include <iostream>

using namespace std;


class Tweet
{
private:
        string message_;
        string user_;
public:
    static const string NULL_USER;
    Tweet(const string& msg = "", const string& user = Tweet :: NULL_USER);
    string getUser();

    bool operator< (const Tweet &rhs)const;
};


#endif //FIRSTEXAMPLE_TWEET_H
