#include "pch.h"
#include "../230705_CRA_Baseball/baseball.cpp"

TEST(BaseballGame, ThrowExceptionWhenInputLenghtIsUnmached) {
  Baseball game;
  EXPECT_THROW(game.guess(string("12")),length_error);
}