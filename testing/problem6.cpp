// 6. ZigZag Conversion
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 0) {
			return std::string();
		}

		int actualLength = s.size();
		int zigLength = numRows > 2 ? numRows - 2 : 0;
		int rowOffset = numRows > 2 ? (numRows + zigLength) : numRows;

		std::string result;
		result.reserve(actualLength);

		// First row.
		for (int i = 0; i < actualLength; i += rowOffset) {
			result += s[i];
		}

		// Middle rows.
		for (int row = 1, end = numRows - 1; row < end; ++row) {
			int zigOffset = numRows - row + zigLength - row;

			for (int i = row, j = row + zigOffset; i < actualLength; i += rowOffset, j += rowOffset) {
				result += s[i];

				if (j < actualLength) {
					result += s[j];
				}
			}
		}

		// End rows.
		if (numRows > 1) {
			for (int i = numRows - 1; i < actualLength; i += rowOffset) {
				result += s[i];
			}
		}

		return result;
	}
};

TEST_CLASS(Test6) {
public:
	TEST_METHOD(TestEmpty) {
		auto solution = Solution();
		auto result = solution.convert("", 0);
		Assert::AreEqual(string(""), result);
	}

	TEST_METHOD(TestEmpty2) {
		auto solution = Solution();
		auto result = solution.convert("", 1);
		Assert::AreEqual(string(""), result);
	}

	TEST_METHOD(TestRow1) {
		auto solution = Solution();
		auto result = solution.convert("TEST", 1);
		Assert::AreEqual(string("TEST"), result);
	}

	TEST_METHOD(TestRow2) {
		auto solution = Solution();
		auto result = solution.convert("TEST", 2);
		Assert::AreEqual(string("TSET"), result);
	}

	TEST_METHOD(TestRow3) {
		auto solution = Solution();
		auto result = solution.convert("PAYPALISHIRING", 3);
		Assert::AreEqual(string("PAHNAPLSIIGYIR"), result);
	}

	TEST_METHOD(TestRow4) {
		auto solution = Solution();
		auto result = solution.convert("PAYPALISHIRING", 4);
		Assert::AreEqual(string("PINALSIGYAHRPI"), result);
	}
};
