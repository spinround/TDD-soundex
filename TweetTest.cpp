//
// Created by andrewyoung5 on 12/18/2018.
//

#include <gmock/gmock.h>
#include "Tweet.h"

using namespace std;
using namespace testing;

TEST(ATweet, DEfaultUserNoNull)
{
    Tweet tweet("msg");
    ASSERT_THAT(tweet.getUser(), Eq("@Null"));
}
TEST(ATweet, Equal)
{
    Tweet tweet("msg","@user");
    Tweet tweetie("msg","@user");
    ASSERT_THAT(tweet, Eq(tweetie));
}
TEST(ATweet, notEqual)
{
    Tweet tweet("msg","@user");
    Tweet tweetie("doopy","@user");
    ASSERT_FALSE(tweet == tweetie);
}