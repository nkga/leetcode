// 220. Contains Duplicate III
class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		// Set can be used since we don't care about which two indices they are, just that they exist.
		// Multi-set isn't needed: if we find a duplicate in the window, it'll always return true.
		std::set<long long> window;
		long long range = t;

		for (int i = 0, n = nums.size(); i < n; ++i) {
			if (i > k) {
				window.erase(nums[i - k - 1]);
			}

			long long value = nums[i];
			auto item = window.lower_bound(value - range);

			if (item != window.end() && *item - value <= range) {
				return true;
			}

			window.insert(value);
		}

		return false;
	}
};
