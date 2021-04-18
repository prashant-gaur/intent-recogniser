#include "DiscoverIntention.h"
#include <gtest.h>
#include <string>
#include <tuple>

class DiscoverIntentionParametersTests : public ::testing::TestWithParam<std::tuple<std::string, std::string> > {
protected:
    DiscoverIntention tool;
};

INSTANTIATE_TEST_CASE_P(
    DiscoverIntentionTests,
    DiscoverIntentionParametersTests,
    ::testing::Values(
        std::make_tuple("Get Weather", "How is the weather in my city ?"),
        std::make_tuple("Check Calendar", "Do I have appointment at 06:00pm today ?"),
        std::make_tuple("Actual intention could not be identified. Try again !!!", "Do I have appointment at 12pm tomo ?"),
        std::make_tuple("Actual intention could not be identified. Try again !!!", "")));

TEST_P(DiscoverIntentionParametersTests, MatchIntention)
{
    //setup
    std::string expected = std::get<0>(GetParam());
    std::string input = std::get<1>(GetParam());
    //action
    std::string actual = tool.find_intention(input);
    //assert
    ASSERT_EQ(expected, actual);
}
