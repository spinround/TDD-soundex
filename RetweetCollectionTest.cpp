//
// Created by andrewyoung5 on 12/17/2018.
//

#include <gmock/gmock.h>
#include "RetweetCollection.h"
#include "Tweet.h"

using namespace testing;
class ARetweetCollection: public Test
{
public:
    RetweetCollection collection;
};
TEST_F(ARetweetCollection, IsEmptyWhenCreated)
{

    ASSERT_TRUE(collection.isEmpty());
}
TEST_F(ARetweetCollection, HasSizeZeroWhenCreated)
{

    ASSERT_THAT(collection.size(), Eq(0u));
}
TEST_F(ARetweetCollection, noLongerEmptyAfterTweet)
{

   collection.add(Tweet());
    ASSERT_FALSE(collection.isEmpty());
}
TEST_F(ARetweetCollection, IsEmptyWhenItsSizeIsZero)
{


    ASSERT_THAT(collection.size(), Eq(0));
    ASSERT_TRUE(collection.isEmpty());
}
TEST_F(ARetweetCollection, IsNotEmptyWhenStuff)
{

    collection.add(Tweet());
    //Gt greater than
    ASSERT_THAT(collection.size(), Gt(0u));
    ASSERT_FALSE(collection.isEmpty());
}

class ARetweetCollectionWithOneTweet : public Test
{
public:
    RetweetCollection collection;
    void SetUp() override
    {
        collection.add(Tweet("msg","@user"));
    };
};

TEST_F(ARetweetCollectionWithOneTweet, IsNoLongerNon)
{
    ASSERT_FALSE(collection.isEmpty());
}
TEST_F(ARetweetCollectionWithOneTweet, SizeOfOne)
{
    ASSERT_THAT(collection.size(),Eq(1u));
}
TEST_F(ARetweetCollectionWithOneTweet, duplicate)
{
    Tweet tweet("msg","@user");
    Tweet duplicate(tweet);
    collection.add(tweet);
    collection.add(duplicate);

    ASSERT_THAT(collection.size(), Eq(1u));
}