// 8. String to Integer (atoi)
class Solution {
public:
	int myAtoi(string str) {
		// Null case.
		if (str.size() == 0) {
			return 0;
		}

		// Easier to work with a null terminated string.
		char const* src = str.c_str();

		// Skip leading spaces.
		int i = 0;
		while (src[i] == ' ') {
			++i;
		}

		// Skip past signs.
		int sign = 1;
		if (src[i] == '-') {
			i += 1;
			sign = -1;
		} else if (src[i] == '+') {
			i += 1;
		}

		// Get numeric characters.
		long long total = 0;

		for (;;) {
			int c = str[i++] - '0';
			if (c < 0 || c > 9) {
				break;
			}
			
			total = (total * 10) + c;
			if (total > INT_MAX) {
				break;
			}
		}

		total = total * sign;
		total = std::min<long long>(total, INT_MAX);
		total = std::max<long long>(total, INT_MIN);
		return (int)total;
	}
};

TEST_CLASS(Test8) {
public:
	TEST_METHOD(TestEmpty) {
		auto solution = Solution();
		auto result = solution.myAtoi("");
		Assert::AreEqual(0, result);
	}

	TEST_METHOD(TestSignPos) {
		auto solution = Solution();
		auto result = solution.myAtoi("+42");
		Assert::AreEqual(42, result);
	}

	TEST_METHOD(TestSignNeg) {
		auto solution = Solution();
		auto result = solution.myAtoi("-42");
		Assert::AreEqual(-42, result);
	}

	TEST_METHOD(TestLeadingZero) {
		auto solution = Solution();
		auto result = solution.myAtoi("042");
		Assert::AreEqual(42, result);
	}

	TEST_METHOD(TestLeadingSpace) {
		auto solution = Solution();
		auto result = solution.myAtoi("   -42");
		Assert::AreEqual(-42, result);
	}

	TEST_METHOD(TestLeadingWords) {
		auto solution = Solution();
		auto result = solution.myAtoi("words and 987");
		Assert::AreEqual(0, result);
	}

	TEST_METHOD(TestEndingWords) {
		auto solution = Solution();
		auto result = solution.myAtoi("4193 with words");
		Assert::AreEqual(4193, result);
	}

	TEST_METHOD(TestOverflowMin) {
		auto solution = Solution();
		auto result = solution.myAtoi("-91283472332");
		Assert::AreEqual(INT_MIN, result);
	}

	TEST_METHOD(TestOverflowMax) {
		auto solution = Solution();
		auto result = solution.myAtoi("812834743325");
		Assert::AreEqual(INT_MAX, result);
	}
};
