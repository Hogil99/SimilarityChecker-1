#include "pch.h"
#include "../Project1/SimilarityChecker.cpp"

class SimilarityCheckerFixture : public testing::Test
{
public:
	SimilarityChecker similarityChecker;
}; 

TEST_F(SimilarityCheckerFixture, length1) {
	EXPECT_THROW(similarityChecker.checkLentghPoint("", ""), std::invalid_argument);
}

TEST_F(SimilarityCheckerFixture, length2) {
	EXPECT_EQ(60, similarityChecker.checkLentghPoint("ABC", "ABC"));
}