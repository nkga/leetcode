// 5. Longest Palindromic Substring
class Solution {
public:
	string longestPalindrome(string s) {
		int total = s.size() * 2 + 3;

		// Transform the string to handle even/odd length palindromes the same, and to avoid bound checks.
		std::vector<int> transform;
		transform.resize(total);

		transform[0] = 256;
		transform[total - 1] = 258;

		for (int is = 0, it = 2, n = s.size(); is < n; is += 1, it += 2) {
			transform[it] = (int)s[is];
		}

		for (int it = 1; it < total; it += 2) {
			transform[it] = 257;
		}

		// Manacher's algorithm.
		std::vector<int> palin(total, 0);

		int center = 0;
		int right = 0;
		int longest_len = 0;
		int longest_idx = 0;

		for (int i = 1, end = total - 1; i < end; ++i) {
			// c - (i - c)
			int mirror = 2 * center - i;

			if (i < right) {
				palin[i] = std::min<int>(right - i, palin[mirror]);
			}

			// Try to expand the palindrome centered at i
			while (transform[i + 1 + palin[i]] == transform[i - 1 - palin[i]]) {
				palin[i] += 1;
			}

			// Update the longest found palindrome.
			if (palin[i] > longest_len) {
				longest_len = palin[i];
				longest_idx = i;
			}

			// If the palindrome centered at i passes r, adjust center
			if (i + palin[i] > right) {
				center = i;
				right = i + palin[i];
			}
		}

		return s.substr((longest_idx - longest_len) / 2, longest_len);
	}
};

TEST_CLASS(Test5) {
public:
	TEST_METHOD(TestEmpty) {
		auto solution = Solution();
		auto result = solution.longestPalindrome("");
		Assert::AreEqual(string(""), result);
	}

	TEST_METHOD(TestSingleChar) {
		auto solution = Solution();
		auto result = solution.longestPalindrome("b");
		Assert::AreEqual(string("b"), result);
	}

	TEST_METHOD(TestSingleString) {
		auto solution = Solution();
		auto result = solution.longestPalindrome("bad");
		Assert::AreEqual(string("b"), result);
	}

	TEST_METHOD(TestExample1) {
		auto solution = Solution();
		auto result = solution.longestPalindrome("babad");
		Assert::AreEqual(string("bab"), result);
	}

	TEST_METHOD(TestExample2) {
		auto solution = Solution();
		auto result = solution.longestPalindrome("cbbd");
		Assert::AreEqual(string("bb"), result);
	}

	TEST_METHOD(TestMiddle) {
		auto solution = Solution();
		auto result = solution.longestPalindrome("abbabd");
		Assert::AreEqual(string("abba"), result);
	}

	TEST_METHOD(TestMultiple) {
		auto solution = Solution();
		auto result = solution.longestPalindrome("abaxabaxabb");
		Assert::AreEqual(string("baxabaxab"), result);
	}
};
