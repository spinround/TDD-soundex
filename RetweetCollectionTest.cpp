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
    Tweet *tweet;
    void SetUp() override
    {
        tweet = new Tweet("msg","@user");
        collection.add(*tweet);
    };


    void TearDown() override
    {
       delete tweet;
       tweet = nullptr;
    }
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
TEST(TestDouble, SumOfFloats)
{
    double x{4.0};
    double y{0.56};
    ASSERT_THAT(x+y, DoubleEq(4.56));

}
TEST(ATweet, RequireUser)
{
    string invalidUser("notStartingWith@");
    ASSERT_ANY_THROW(Tweet tweet("msg",invalidUser));
}