#include <iostream>

using namespace std;

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

	int checkLentghPoint(const string str1,const string str2)
	{
		isIllegalArgumentFound(str1, str2);

		if (str1.length() == str2.length())
			return 60;


	}
};