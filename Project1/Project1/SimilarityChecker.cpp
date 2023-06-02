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

	unordered_set<char> getTotalAlphaList(const string& str1, const string& str2)
	{
		unordered_set<char> totalAlphaList;
		for (char c : str1)
		{
			if (!totalAlphaList.count(c))
				totalAlphaList.insert(c);
		}

		for (char c : str2)
		{
			if (!totalAlphaList.count(c))
				totalAlphaList.insert(c);
		}
		return totalAlphaList;
	}

	unordered_set<char> getAlphaList(const string& str)
	{
		unordered_set<char> totalAlphaList;
		for (char c : str)
		{
			if (!totalAlphaList.count(c))
				totalAlphaList.insert(c);
		}
		return totalAlphaList;
	}


	int getAlphaScore()
	{
		int sameCnt = 0;
		for (char c : totalAlphaList)
		{
			if (aAlphaList.count(c) && bAlphaList.count(c))
				sameCnt++;
		}
		return (sameCnt * 40) / totalAlphaList.size();
	}

	int checkAlpha(const string& str1, const string& str2)
	{
		isEmptyStr(str1);
		isEmptyStr(str2);

		isIllegalAlphabet(str1);
		isIllegalAlphabet(str2);

		if (str1 == str2) return 40;

		aAlphaList = getAlphaList(str1);
		bAlphaList = getAlphaList(str2);

		totalAlphaList = getTotalAlphaList(str1, str2);

		return getAlphaScore();
	}

private:
	unordered_set<char> aAlphaList;
	unordered_set<char> bAlphaList;
	unordered_set<char> totalAlphaList;
	int longLength;
	int shortLength;
};