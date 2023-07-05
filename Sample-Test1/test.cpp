#include "pch.h"
#include "../230705_CRA_Baseball/baseball.cpp"

class BaseballFixture : public testing::Test {
public:
	Baseball game;
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
}