#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int LENGTH_MAX_RESULT = 60;

class SimilarityChecker
{
public:
	void isEmptyStr(const string str1)
	{
		if (str1 == "")
		{
			throw std::invalid_argument("빈 문자열이 있어요.");
		}
	}

	void isIllegalAlphabet(const string str1)
	{
		for(char c : str1)
		{
			if (c < 'A' || c > 'Z')
				throw std::invalid_argument("잘못된 Alphabet");
		}
	}

	void isIllegalAlphabetFound(const string str1, const string str2)
	{
		isIllegalAlphabet(str1);
	}

	void getLongShortLenghs(const string str1, const string str2)
	{
		if (str1.length() > str2.length())
		{
			longLength = str1.length();
			shortLength = str2.length();
			return;
		} 

		longLength = str2.length();
		shortLength = str1.length();
	}

	bool isLengthSame(const string str1, const string str2)
	{
		return str1.length() == str2.length();
	}

	int getScore()
	{
		int gap = longLength - shortLength;
		return (shortLength - gap) * LENGTH_MAX_RESULT / shortLength;
	}

	int checkLentghPoint(const string str1,const string str2)
	{
		isEmptyStr(str1);
		isEmptyStr(str2);

		if (isLengthSame(str1, str2))
			return LENGTH_MAX_RESULT;

		getLongShortLenghs(str1, str2);

		return getScore();
	}

	int checkAlpha(const string& str1, const string& str2)
	{
		isEmptyStr(str1);
		isEmptyStr(str2);
		;
		isIllegalAlphabet(str1);
		isIllegalAlphabet(str2);

		if (str1 == str2) return 40;

		for (char c : str1)
		{
			if (!aAlphaSet.count(c))
				aAlphaSet.insert(c);
			if (!totalAlphaList.count(c))
				totalAlphaList.insert(c);
		}

		for (char c : str2)
		{
			if (!bAlphaList.count(c))
				bAlphaList.insert(c);
			if (!totalAlphaList.count(c))
				totalAlphaList.insert(c);
		}

		int result = 0;
		int sameCnt = 0;
		int totalCnt = totalAlphaList.size();

		for (char c : totalAlphaList)
		{
			if (aAlphaSet.count(c) && bAlphaList.count(c))
				sameCnt++;
		}

		result = (sameCnt * 40) / totalCnt;
	}

private:
	unordered_set<char> aAlphaSet;
	unordered_set<char> bAlphaList;
	unordered_set<char> totalAlphaList;
	int longLength;
	int shortLength;
};