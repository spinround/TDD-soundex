//
// Created by andrewyoung5 on 12/18/2018.
//

#include <gmock/gmock.h>
#include "Tweet.h"

using namespace std;
using namespace ::testing;

TEST(ATweet, DEfaultUserNoNull)
{
    Tweet tweet("msg");
    ASSERT_THAT(tweet.getUser(), Eq("@Null"));
}