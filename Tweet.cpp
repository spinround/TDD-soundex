//
// Created by andrewyoung5 on 12/17/2018.
//

#include "Tweet.h"

const std::string Tweet::NULL_USER("@Null");

Tweet::Tweet(const string &msg, const string &user)
{
    message_ = msg;
    user_ = user;
}

bool Tweet::operator<(const Tweet &rhs) const
{
    if(message_ < rhs.message_)
        return true;
    if(rhs.message_ < message_)
        return false;

    return user_ < rhs.user_;
}

string Tweet::getUser() {
    return user_;
}

bool Tweet::operator==(const Tweet &rhs) const {
    return message_ == rhs.message_ &&
           user_ == rhs.user_;
}

bool Tweet::operator!=(const Tweet &rhs) const {
    return !(rhs == *this);
}
