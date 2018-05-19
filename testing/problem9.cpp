// 9. Palindrome Number
class Solution {
public:
	bool isPalindrome(int x) {
		// Negative numbers will always fail because of the sign.
		if (x < 0) {
			return false;
		}

		// No palindrome number can start with a leading zero other than zero itself.
		if (x != 0 && (x % 10) == 0) {
			return false;
		}

		// Keep going until we're roughly halfway through the "number" conversion.
		int pal = 0;
		while (x > pal) {
			pal = (pal * 10) + (x % 10);
			x /= 10;
		}

		// Check if the two "halves" are equal. Need to add extra check for "even" length palindromes.
		return (x == pal) || (x == pal / 10);
	}
};

TEST_CLASS(Test9) {
public:
	TEST_METHOD(TestEmpty) {
		auto solution = Solution();
		auto result = solution.isPalindrome(0);
		Assert::AreEqual(true, result);
	}

	TEST_METHOD(TestPositive) {
		auto solution = Solution();
		auto result = solution.isPalindrome(121);
		Assert::AreEqual(true, result);
	}

	TEST_METHOD(TestNegative) {
		auto solution = Solution();
		auto result = solution.isPalindrome(-121);
		Assert::AreEqual(false, result);
	}

	TEST_METHOD(TestInvalid) {
		auto solution = Solution();
		auto result = solution.isPalindrome(10);
		Assert::AreEqual(false, result);
	}

	TEST_METHOD(TestEvenLength) {
		auto solution = Solution();
		auto result = solution.isPalindrome(12344321);
		Assert::AreEqual(true, result);
	}
};
