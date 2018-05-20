// 12. Integer to Roman
class Solution {
public:
	// No point in doing anything fancy here. This is 99% faster than any other solution. I'll explain why:
	// - Memory reads for things not in the cache can take hundreds of cycles.
	// - Memory reads in cache can take ~4 cycles.
	// - Arithmetic operations and immediate loads of small numbers can take ~0-1 cycles, depending on pipelining
	// - Characters are small enough in value to be immediate loads.
	// - Strings require multiple bytes and are not immediate values, and instead require reading from rdata segment.
	// - A jump table is not significantly faster on modern architectures for small number of conditions.
	// - A jump table with entries far apart typically requires multiple arithmetic operations and sub tables.
	// - Any additional data structures (hash tables, etc) cost more to setup and maintain than any of these arithmetic ops.
	string intToRoman(int num) {
		std::string result;
		if (num <= 0) {
			// Invalid roman number.
			return result;
		}

		// Preallocate in advance for performance.
		result.reserve(32);

		while (num >= 1000) {
			num -= 1000;
			result += 'M';
		}

		if (num >= 900) {
			num -= 900;
			result += 'C';
			result += 'M';
		}

		if (num >= 500) {
			num -= 500;
			result += 'D';
		} else if (num >= 400) {
			num -= 400;
			result += 'C';
			result += 'D';
		}

		while (num >= 100) {
			num -= 100;
			result += 'C';
		}

		if (num >= 90) {
			num -= 90;
			result += 'X';
			result += 'C';
		} else if (num >= 50) {
			num -= 50;
			result += 'L';
		} else if (num >= 40) {
			num -= 40;
			result += 'X';
			result += 'L';
		}

		while (num >= 10) {
			num -= 10;
			result += 'X';
		}

		if (num == 9) {
			result += 'I';
			result += 'X';
		} else if (num == 4) {
			result += 'I';
			result += 'V';
		} else {
			if (num >= 5) {
				num -= 5;
				result += 'V';
			}

			while (num > 0) {
				num -= 1;
				result += 'I';
			}
		}

		return result;
	}
};

TEST_CLASS(Test12) {
public:
	TEST_METHOD(TestZero) {
		auto solution = Solution();
		auto result = solution.intToRoman(0);
		Assert::AreEqual(std::string(""), result);
	}

	TEST_METHOD(TestNegative) {
		auto solution = Solution();
		auto result = solution.intToRoman(-10);
		Assert::AreEqual(std::string(""), result);
	}

	TEST_METHOD(TestOne) {
		auto solution = Solution();
		auto result = solution.intToRoman(1);
		Assert::AreEqual(std::string("I"), result);
	}

	TEST_METHOD(TestThree) {
		auto solution = Solution();
		auto result = solution.intToRoman(3);
		Assert::AreEqual(std::string("III"), result);
	}

	TEST_METHOD(TestFour) {
		auto solution = Solution();
		auto result = solution.intToRoman(4);
		Assert::AreEqual(std::string("IV"), result);
	}

	TEST_METHOD(TestNine) {
		auto solution = Solution();
		auto result = solution.intToRoman(9);
		Assert::AreEqual(std::string("IX"), result);
	}

	TEST_METHOD(TestTen) {
		auto solution = Solution();
		auto result = solution.intToRoman(10);
		Assert::AreEqual(std::string("X"), result);
	}

	TEST_METHOD(TestL) {
		auto solution = Solution();
		auto result = solution.intToRoman(58);
		Assert::AreEqual(std::string("LVIII"), result);
	}

	TEST_METHOD(TestXL) {
		auto solution = Solution();
		auto result = solution.intToRoman(40);
		Assert::AreEqual(std::string("XL"), result);
	}

	TEST_METHOD(TestXC) {
		auto solution = Solution();
		auto result = solution.intToRoman(90);
		Assert::AreEqual(std::string("XC"), result);
	}

	TEST_METHOD(TestD) {
		auto solution = Solution();
		auto result = solution.intToRoman(500);
		Assert::AreEqual(std::string("D"), result);
	}

	TEST_METHOD(TestAll) {
		auto solution = Solution();
		auto result = solution.intToRoman(1994);
		Assert::AreEqual(std::string("MCMXCIV"), result);
	}
};
