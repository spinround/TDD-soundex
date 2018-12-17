//
// Created by andrewyoung5 on 12/17/2018.
//

#include "RetweetCollection.h"


bool RetweetCollection::isEmpty()
{
    return size() == 0;
}

int RetweetCollection::size()
{
    return size_;
}

void RetweetCollection::add(Tweet tweet)
{
    size_++;
}

RetweetCollection::RetweetCollection()
{
    size_ = 0;
}


