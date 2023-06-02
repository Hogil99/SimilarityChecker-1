#include <iostream>

using namespace std;

const int LENGTH_MAX_RESULT = 60;

class SimilarityChecker
{
public:
	void isIllegalArgumentFound(const string str1,const string str2)
	{
		if (str1 == "" || str2 == "")
		{
			throw std::invalid_argument("빈 문자열이 있어요.");
		}
	}

	void getLongShortLenghs(const string str1, const string str2)
	{
		if (str1.length() > str2.length())
		{
			longLength = str1.length();
			shortLength = str2.length();
		} else
		{
			longLength = str2.length();
			shortLength = str1.length();
		}
	}

	bool isLengthSame(const string str1, const string str2)
	{
		return str1.length() == str2.length();
	}

	int getScore()
	{
		int gap = longLength - shortLength;
		return (1 - (double)gap / (double)shortLength) * LENGTH_MAX_RESULT;
	}

	int checkLentghPoint(const string str1,const string str2)
	{
		isIllegalArgumentFound(str1, str2);

		if (isLengthSame(str1, str2))
			return LENGTH_MAX_RESULT;

		getLongShortLenghs(str1, str2);

		return getScore();
	}

private:
	int longLength;
	int shortLength;
};