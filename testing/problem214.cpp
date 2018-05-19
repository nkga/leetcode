// 214. Shortest Palindrome
class Solution {
public:
	// time: O(n^2), space: O(n)
	// Goal is to come back to this eventually but it's competitive
	// with most of the submissions despite its simplicity.
	string shortestPalindrome(string s) {
		int len = s.size();

		std::string r;
		r.reserve(len);

		for (int i = len - 1; i >= 0; --i) {
			r += s[i];
		}

		auto cs = s.c_str();
		auto rs = r.c_str();

		for (int i = 0; i < len; ++i) {
			if (strncmp(cs, rs + i, len - i) == 0) {
				return r.substr(0, i) + s;
			}
		}

		return s;
	}
};

TEST_CLASS(Test214) {
public:
	TEST_METHOD(TestEmpty) {
		auto solution = Solution();
		auto result = solution.shortestPalindrome("");
		Assert::AreEqual(std::string(""), result);
	}

	TEST_METHOD(TestSingle) {
		auto solution = Solution();
		auto result = solution.shortestPalindrome("a");
		Assert::AreEqual(std::string("a"), result);
	}

	TEST_METHOD(TestEven) {
		auto solution = Solution();
		auto result = solution.shortestPalindrome("ba");
		Assert::AreEqual(std::string("aba"), result);
	}

	TEST_METHOD(TestPalindrome) {
		auto solution = Solution();
		auto result = solution.shortestPalindrome("aaacecaaa");
		Assert::AreEqual(std::string("aaacecaaa"), result);
	}

	TEST_METHOD(TestMinChange) {
		auto solution = Solution();
		auto result = solution.shortestPalindrome("aacecaaa");
		Assert::AreEqual(std::string("aaacecaaa"), result);
	}

	TEST_METHOD(TestMaxChange) {
		auto solution = Solution();
		auto result = solution.shortestPalindrome("abcd");
		Assert::AreEqual(std::string("dcbabcd"), result);
	}

	TEST_METHOD(TestPartialPalindrome) {
		auto solution = Solution();
		auto result = solution.shortestPalindrome("abbacd");
		Assert::AreEqual(std::string("dcabbacd"), result);
	}

	TEST_METHOD(TestDoubleInterior) {
		auto solution = Solution();
		auto result = solution.shortestPalindrome("aabba");
		Assert::AreEqual(std::string("abbaabba"), result);
	}
};
