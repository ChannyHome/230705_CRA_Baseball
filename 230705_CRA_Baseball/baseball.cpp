#include <string>
#include <stdexcept>
using namespace std;

struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	Baseball();

	explicit Baseball(const string& question)
		: question(question) {

	}

	GuessResult guess(const string& guessNumber)
	{
		assertIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return { true, 3, 0 };
		}
		bool solved = false;
		//
		int strikeCnt = getStrikeCnt(guessNumber);
		//
		int ballCnt = getBallCnt(guessNumber);

		return { solved, strikeCnt, ballCnt };
	}


	GuessResult guess_CK(const string& guessNumber)
	{
		assertIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return { true, 3, 0 };
		}
		//
		int strikeCnt = 0;
		int ballCnt = 0;
		for (int i = 0; i < guessNumber.size(); i++)
		{
			if (question[i] == guessNumber[i])
				strikeCnt++;
			else
			{
				if (question.find(guessNumber[i]) != string::npos)
					ballCnt++;
			}

		}
		//2strike 0 ball
		//1strike 2 ball
		return { false, strikeCnt, ballCnt };
	}

private:
	string question;
	bool isDuplicatedNumber(const string& guessNumber)
	{
		bool isResult = false;
		if (guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2])
			isResult = true;
		return isResult;
	}
	void assertIllegalArgument(const string& guessNumber)
	{
		if (guessNumber.length() != 3)
			throw length_error("Must be three letters");
		for (char ch : guessNumber)
		{
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}
		if (isDuplicatedNumber(guessNumber))
			throw invalid_argument("Must not have the same number");
	}

	int getStrikeCnt(const string&  guessNumber)
	{
		int result = 0;
		for (int i = 0; i < guessNumber.size(); i++)
		{
			if (question[i] != guessNumber[i]) continue;
			result++;
		}
		return result;
	}

	int getBallCnt(const string& guessNumber)
	{
		int result = 0;
		for (int i = 0; i < guessNumber.size(); i++)
		{
			for (int x = 0; x < question.size(); x++)
			{
				if(i == x) continue;
				if (question[x] == guessNumber[i])
					result++;
			}
		}
		return result;
	}

};

