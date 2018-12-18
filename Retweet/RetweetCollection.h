//
// Created by andrewyoung5 on 12/17/2018.
//

#ifndef FIRSTEXAMPLE_RETWEETCOLLECTION_H
#define FIRSTEXAMPLE_RETWEETCOLLECTION_H
#include "Tweet.h"
#include <set>



class RetweetCollection {
private:
    unsigned int size_;
    set<Tweet> tweets;
public:
    RetweetCollection();
    bool isEmpty();
    int size();
    void add(Tweet tweet);


};


#endif //FIRSTEXAMPLE_RETWEETCOLLECTION_H
