// 10. Regular Expression Matching
class Solution {
public:
	bool isMatch(string s, string p) {
		// This uses a dynamic programming approach to solving the problem.
		// If you don't case about multiple Kleene stars in a row, you can
		// swap this out for an O(n) solution that works backwards and is
		// much faster.
		//
		// However, to solve this problem we need to handle the case of
		// the Kleene star eating a character or not eating one.
		// And the easiest way to handle both of these cases is by breaking
		// up the problem into smaller optimial subproblems with DP.
		//
		// We build a matrix that asks whether or not str[i:] == pat[j:]
		// but also make sure the matrix is DP[len(str) + 1][len(pat) + 1].
		// The empty pattern and the empty string will always match, of course.
		//
		// The diagonal of the matrix will be a straight line of 1s to DP[0][0]
		// for two strings without any kleene stars.
		//
		// The Kleene star will only pass if the character after it in the pattern
		// string is matched OR the Kleene star ate the next character.
		//
		// It's easiest to fill in the matrix working backwards.
		// Here's an example of what the DP matrix looks like at the end:
		//    a * a
		// a  1 0 0 0
		// a  1 0 0 0 
		// a  1 0 1 0
		//    0 1 0 1
		//
		// In this case you can see the Kleene star could potentially
		// eat 'a's until the end of the string. But this won't give us the right answer.
		// But we see that the last two 'a's match, in DP[2][2]. So when we look at
		// the Kleene star 'a' in DP[2][0], we use that DP[2][2] to carry upward in
		// DP[1][0] and DP[0][0].

		if (p.size() == 0) {
			// Empty pattern only matches empty string.
			return s.size() == 0;
		}

		int pnum = p.size() + 1;
		int snum = s.size() + 1;

		auto get_idx = [&](int i, int j) {
			return i * pnum + j;
		};

		std::vector<bool> dp(pnum * snum, false);

		// End of both strings match.
		dp[get_idx(s.size(), p.size())] = true;

		// Working with substrings s[:] and p[:]
		int sn = s.size();
		int pn = p.size();

		for (int i = sn; i >= 0; --i) {
			for (int j = pn - 1; j >= 0; --j) {
				bool matched = (i < sn && (p[j] == '.' || p[j] == s[i]));

				if (j + 1 < pn && p[j + 1] == '*') {
					// Kleene star case, check if we're continuing off a valid match or the next character in the pattern matches.
					dp[get_idx(i, j)] = dp[get_idx(i, j + 2)] || (matched && dp[get_idx(i + 1, j)]);
				} else {
					// This substr and the next one need to match.
					dp[get_idx(i, j)] = matched && dp[get_idx(i + 1, j + 1)];
				}
			}
		}

		return dp[0];
	}
};

TEST_CLASS(Test10) {
public:
	TEST_METHOD(TestEmpty) {
		auto solution = Solution();
		auto result = solution.isMatch("", "");
		Assert::AreEqual(true, result);
	}

	TEST_METHOD(TestExample1) {
		auto solution = Solution();
		auto result = solution.isMatch("aa", "a");
		Assert::AreEqual(false, result);
	}

	TEST_METHOD(TestExample2) {
		auto solution = Solution();
		auto result = solution.isMatch("aa", "a*");
		Assert::AreEqual(true, result);
	}

	TEST_METHOD(TestExample3) {
		auto solution = Solution();
		auto result = solution.isMatch("ab", ".*");
		Assert::AreEqual(true, result);
	}

	TEST_METHOD(TestExample4) {
		auto solution = Solution();
		auto result = solution.isMatch("aab", "c*a*b");
		Assert::AreEqual(true, result);
	}

	TEST_METHOD(TestExample5) {
		auto solution = Solution();
		auto result = solution.isMatch("mississippi", "mis*is*p*.");
		Assert::AreEqual(false, result);
	}

	TEST_METHOD(TestExample6) {
		auto solution = Solution();
		auto result = solution.isMatch("aaa", "ab*a*c*a");
		Assert::AreEqual(true, result);
	}

	TEST_METHOD(TestExampleMultiFalse) {
		auto solution = Solution();
		auto result = solution.isMatch("ab", ".*c");
		Assert::AreEqual(false, result);
	}

	TEST_METHOD(TestExampleMultiTrue) {
		auto solution = Solution();
		auto result = solution.isMatch("aaa", "a*a");
		Assert::AreEqual(true, result);
	}

	TEST_METHOD(TestInvalidKleene) {
		auto solution = Solution();
		auto result = solution.isMatch("aaa", "a**");
		Assert::AreEqual(false, result);
	}
};
