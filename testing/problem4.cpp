// 4. Median of Two Sorted Arrays
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int total = nums1.size() + nums2.size();
		if (total == 0) {
			return 0.0;
		}

		int mid = (total / 2);
		int n1 = nums1.size();
		int n2 = nums2.size();
		int num = 0, last = 0, i1 = 0, i2 = 0;

		for (;;) {
			if (num >= mid) {
				int med;

				if (i1 < n1 && i2 < n2) {
					med = std::min(nums1[i1], nums2[i2]);
				} else {
					med = (i1 < n1) ? nums1[i1] : nums2[i2];
				}

				return ((total & 1) == 0) ? ((last + med) / 2.0) : med;
			}

			if (i1 < n1 && i2 < n2) {
				int v1 = nums1[i1];
				int v2 = nums2[i2];

				if (v1 <= v2) {
					last = v1;
					i1 += 1;
				} else {
					last = v2;
					i2 += 1;
				}
			} else if (i1 < n1) {
				last = nums1[i1++];
			} else {
				last = nums2[i2++];
			}

			num += 1;
		}

		return 0.0;
	}
};
