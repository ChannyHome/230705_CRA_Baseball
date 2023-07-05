#include <string>
#include <stdexcept>
using namespace std;

class Baseball
{
public:
	Baseball();
	~Baseball();

	



	void guess(const string& guessNumber)
	{
		assertIllegalArgument(guessNumber);
	}

private:
	bool isDuplicatedNumber(const string& guessNumber)
	{
		bool isResult = false;
		if (guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2])
			isResult = true;
		return true;
	}
	void assertIllegalArgument(const string& guessNumber)
	{
		if (guessNumber.length() != 3)
			throw length_error("Must be three letters");
		for (char ch : guessNumber)
		{
			if (ch >= '0' && ch <= '9')
				throw invalid_argument("Must be number");
		}
		if (isDuplicatedNumber(guessNumber))
			throw invalid_argument("Must not have the same number");
	}

};

Baseball::Baseball()
{
}

Baseball::~Baseball()
{
}