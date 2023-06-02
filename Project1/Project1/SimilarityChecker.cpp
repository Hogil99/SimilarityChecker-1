#include <iostream>

using namespace std;

class SimilarityChecker
{
public:
	void isIllegalArgumentFound(string str1, string str2)
	{
		if (str1 == "" || str2 == "")
		{
			throw std::invalid_argument("빈 문자열이 있어요.");
		}
	}

	int checkLentghPoint(string str1, string str2)
	{
		isIllegalArgumentFound(str1, str2);
	}
};