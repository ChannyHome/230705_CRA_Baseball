#include <string>
#include <stdexcept>
using namespace std;

class Baseball
{
public:
	Baseball();
	~Baseball();
	void guess(const string& string)
	{
		if (string.length() != 3)
			throw length_error("Must be three letters");
		for (char ch : string)
		{
			if (ch < '0' || ch > '9')
				throw invalid_argument("Must be number");
		}
	}

private:

};

Baseball::Baseball()
{
}

Baseball::~Baseball()
{
}