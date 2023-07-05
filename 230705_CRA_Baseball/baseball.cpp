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
	}

private:

};

Baseball::Baseball()
{
}

Baseball::~Baseball()
{
}