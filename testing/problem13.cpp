class Solution {
public:
	// Nothing too fancy about this one.
	// time: O(n), space O(1)

	// Can replace this with a table, but it's slower.
	static inline int romanCharValue(char c) {
		switch (c) {
			case 'I':
				return 1;
			case 'V':
				return 5;
			case 'X':
				return 10;
			case 'L':
				return 50;
			case 'C':
				return 100;
			case 'D':
				return 500;
			case 'M':
				return 1000;
		}
		return 0;
	}

	int romanToInt(string s) {
		auto str = (unsigned char const*)s.c_str();
		auto end = str + s.size();

		int total = 0;
		int lastValue = romanCharValue(*str++);

		while (str < end) {
			int value = romanCharValue(*str++);
			total += value <= lastValue ? lastValue : -lastValue;
			lastValue = value;
		}

		total += lastValue;
		return total;
	}
};

TEST_CLASS(Test13) {
public:
	TEST_METHOD(TestZero) {
		auto solution = Solution();
		auto result = solution.romanToInt("");
		Assert::AreEqual(0, result);
	}

	TEST_METHOD(TestOne) {
		auto solution = Solution();
		auto result = solution.romanToInt("I");
		Assert::AreEqual(1, result);
	}

	TEST_METHOD(TestThree) {
		auto solution = Solution();
		auto result = solution.romanToInt("III");
		Assert::AreEqual(3, result);
	}

	TEST_METHOD(TestFour) {
		auto solution = Solution();
		auto result = solution.romanToInt("IV");
		Assert::AreEqual(4, result);
	}

	TEST_METHOD(TestNine) {
		auto solution = Solution();
		auto result = solution.romanToInt("IX");
		Assert::AreEqual(9, result);
	}

	TEST_METHOD(TestTen) {
		auto solution = Solution();
		auto result = solution.romanToInt("X");
		Assert::AreEqual(10, result);
	}

	TEST_METHOD(TestExample4) {
		auto solution = Solution();
		auto result = solution.romanToInt("LVIII");
		Assert::AreEqual(58, result);
	}

	TEST_METHOD(TestExample5) {
		auto solution = Solution();
		auto result = solution.romanToInt("MCMXCIV");
		Assert::AreEqual(1994, result);
	}
};
