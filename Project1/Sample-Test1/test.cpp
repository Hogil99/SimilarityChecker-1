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