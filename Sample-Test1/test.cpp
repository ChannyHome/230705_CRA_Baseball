#include "pch.h"
#include "../230705_CRA_Baseball/baseball.cpp"

class BaseballFixture : public testing::Test {
public:
	Baseball game{ "123" };
	void assertIllegalArgument(string guessNumber) {
		//game.guess() 수행 후 Exception이 발행해야 pass
		try
		{
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e)
		{
			//pass
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {

	GuessResult result = game.guess("123");
	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);

}

TEST_F(BaseballFixture, Return2strike0ball) {

	GuessResult result = game.guess("129");
	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);

}

TEST_F(BaseballFixture, Return1strike2ball) {

	GuessResult result = game.guess("321");
	EXPECT_FALSE(result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(2, result.balls);

}