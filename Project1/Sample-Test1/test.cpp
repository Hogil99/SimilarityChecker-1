#include "pch.h"
#include "../Project1/SimilarityChecker.cpp"

TEST(LengthCheckTest, length1) {
	SimilarityChecker similarityChecker;
	EXPECT_THROW(similarityChecker.checkLentghPoint("", ""), std::invalid_argument);
}