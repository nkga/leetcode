// 7. Reverse Integer
class Solution {
public:
	int reverse(int x) {
		// Could alternatively precheck in every iteration if it exceeds INT_MAX/10
		// if long long isn't desired. This method avoids the check, though.
		long long value = x;
		
		int sign = (value >= 0ll) ? 1 : -1;
		value *= sign;

		long long total = 0;

		while (value > 0) {
			total = (total * 10) + (value % 10);
			value /= 10;
		}

		if (total > INT_MAX) {
			return 0;
		}

		return (int)(total * sign);
	}
};

TEST_CLASS(Test7) {
public:
	TEST_METHOD(TestZero) {
		auto solution = Solution();
		auto result = solution.reverse(0);
		Assert::AreEqual(0, result);
	}

	TEST_METHOD(TestNegativeSingle) {
		auto solution = Solution();
		auto result = solution.reverse(-1);
		Assert::AreEqual(-1, result);
	}

	TEST_METHOD(TestNegativeMultiple) {
		auto solution = Solution();
		auto result = solution.reverse(-123);
		Assert::AreEqual(-321, result);
	}

	TEST_METHOD(TestPositiveSingle) {
		auto solution = Solution();
		auto result = solution.reverse(1);
		Assert::AreEqual(1, result);
	}

	TEST_METHOD(TestPositiveMultiple) {
		auto solution = Solution();
		auto result = solution.reverse(123);
		Assert::AreEqual(321, result);
	}

	TEST_METHOD(TestEndingZero) {
		auto solution = Solution();
		auto result = solution.reverse(120);
		Assert::AreEqual(21, result);
	}

	TEST_METHOD(TestOverflow) {
		auto solution = Solution();
		auto result = solution.reverse(1534236469);
		Assert::AreEqual(0, result);
	}
};
