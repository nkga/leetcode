// 3. Longest Substring Without Repeating Characters
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int pos[128];
		int longest = 0;
		int current = 0;

		memset(pos, 0, sizeof(pos));

		for (int i = 0, n = s.size(); i < n; ++i) {
			char c = s[i];
			current = std::max(pos[c], current);
			longest = std::max(longest, i - current + 1);
			pos[c] = i + 1;
		}

		return longest;
	}
};

