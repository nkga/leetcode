// 1. Two Sum
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		std::vector<int> result;
		result.reserve(2);

		std::unordered_map<int, int> values;
		values.reserve(nums.size());

		for (int i = 0, n = nums.size(); i < n; ++i) {
			int value = nums[i];
			int needed = target - value;

			auto item = values.find(needed);
			if (item != values.end()) {
				result.push_back(item->second);
				result.push_back(i);
				break;
			}

			values[value] = i;
		}

		return result;
	}
};
