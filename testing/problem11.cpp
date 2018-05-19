// 11. Container With Most Water
class Solution {
public:
	int maxArea(vector<int>& height) {
		// We don't care about what two points that make the max area, just the value.
		// Move inward from both sides looking for the tallest heights.

		int left = 0;
		int right = height.size() - 1;
		int area = 0;

		while (left < right) {
			int boxWidth = right - left;
			int boxHeight = std::min<int>(height[right], height[left]);
			area = std::max<int>(area, boxWidth * boxHeight);

			if (height[left] > height[right]) {
				right -= 1;
			} else {
				left += 1;
			}
		}

		return area;
	}
};

TEST_CLASS(Test11) {
public:
	TEST_METHOD(TestEmpty) {
		std::vector<int> test;
		auto solution = Solution();
		auto result = solution.maxArea(test);
		Assert::AreEqual(0, result);
	}

	TEST_METHOD(TestSingle) {
		std::vector<int> test = { 1 };
		auto solution = Solution();
		auto result = solution.maxArea(test);
		Assert::AreEqual(0, result);
	}

	TEST_METHOD(TestValid) {
		std::vector<int> test = { 1, 1 };
		auto solution = Solution();
		auto result = solution.maxArea(test);
		Assert::AreEqual(1, result);
	}

	TEST_METHOD(TestHeightDifference) {
		std::vector<int> test = { 1, 2, 1, 0, 4 };
		auto solution = Solution();
		auto result = solution.maxArea(test);
		Assert::AreEqual(6, result);
	}
};
