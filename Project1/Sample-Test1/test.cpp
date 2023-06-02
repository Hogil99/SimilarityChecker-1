#include "pch.h"
#include "../Project1/SimilarityChecker.cpp"

class SimilarityCheckerFixture : public testing::Test
{
public:
	SimilarityChecker similarityChecker;
}; 

TEST_F(SimilarityCheckerFixture, illegalArgument) {
	EXPECT_THROW(similarityChecker.checkLentghPoint("", ""), std::invalid_argument);
}

TEST_F(SimilarityCheckerFixture, length1) {
	EXPECT_EQ(60, similarityChecker.checkLentghPoint("ABC", "ABC"));
}

TEST_F(SimilarityCheckerFixture, length2) {
	EXPECT_EQ(0, similarityChecker.checkLentghPoint("A", "BB"));
	EXPECT_EQ(40, similarityChecker.checkLentghPoint("ABBB", "BBB"));
	EXPECT_EQ(40, similarityChecker.checkLentghPoint("BBB", "ABBB"));

	EXPECT_EQ(20, similarityChecker.checkLentghPoint("ABBBB", "BBB"));
	EXPECT_EQ(20, similarityChecker.checkLentghPoint("BBB", "ABBBB"));

	EXPECT_EQ(55, similarityChecker.checkLentghPoint("AAAAABBBBBAAAAABBBBBAAAAABBBBBAAAAABBBBBAAAAABBBBBAAAAABBBBBAAAAA", "AAAAABBBBBAAAAABBBBBAAAAABBBBBAAAAABBBBBAAAAABBBBBAAAAABBBBB"));
}


TEST_F(SimilarityCheckerFixture, alphaIllegal)
{
	EXPECT_THROW(similarityChecker.checkAlpha("", ""), std::invalid_argument);
	EXPECT_THROW(similarityChecker.checkAlpha("ABC", "ABc"), std::invalid_argument);
}



TEST_F(SimilarityCheckerFixture, alphaSame)
{
	EXPECT_EQ(40, similarityChecker.checkAlpha("AA", "AA"));
	EXPECT_EQ(40, similarityChecker.checkAlpha("BBB", "BBB"));
	EXPECT_EQ(40, similarityChecker.checkAlpha("CCCC", "CCCC"));
}

TEST_F(SimilarityCheckerFixture, alphaPartial)
{
	EXPECT_EQ(20, similarityChecker.checkAlpha("AB", "AA"));
	EXPECT_EQ(26, similarityChecker.checkAlpha("ABC", "AACCC"));

}

