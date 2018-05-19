// 315. Count of Smaller Numbers After Self
class Solution {
public:
	class StatsTree {
	public:
		StatsTree(int capacity) : head(nullptr), num(0) {
			data = new Node[capacity];
		}

		~StatsTree() {
			delete[] data;
		}

		int insert(int value) {
			if (head == nullptr) {
				head = new_node(value);
				return 0;
			}

			int count = 0;

			Node* node = head;
			for (;;) {
				Node* next;
				if (value >= node->value) {
					count += node->count + (node->value != value);
					next = node->right;

					if (next == nullptr) {
						node->right = new_node(value);
						return count;
					}
				} else {
					node->count += 1;
					next = node->left;

					if (next == nullptr) {
						node->left = new_node(value);
						return count;
					}
				}

				node = next;
			}
			
			return count;
		}
	protected:
		struct Node {
			Node* left;
			Node* right;
			int value;
			int count;
		};

		Node* new_node(int value) {
			Node* node = &data[num++];
			node->left = nullptr;
			node->right = nullptr;
			node->value = value;
			node->count = 0;
			return node;
		}

		int num;
		Node* head;
		Node* data;
	};

	// time: O(nlog(n) (average), O(n^2) worst, space: O(n)
	// This utilizies a modified binary tree that keeps track of the number
	// of nodes on the left hand side. Since countSmaller only cares about
	// nodes right of the current index we can traverse the list right-to-left
	// and completely ignore having to implement any sort of deletion
	// operations. No self-balancing to handle improving the O(n^2) case,
	// but it's not really needed. This is 95% faster than everyone else's
	// solution anyway.
	//
	// I think another approach to this problem would involve counting
	// bits and maintaining some sort of bit lookup table...
	vector<int> countSmaller(vector<int>& nums) {
		int size = nums.size();

		std::vector<int> result;
		result.resize(size);

		StatsTree tree(size);
		for (int i = size - 1; i >= 0; --i) {
			result[i] = tree.insert(nums[i]);
		}

		return result;
	}
};

TEST_CLASS(Test315) {
public:
	static void AssertVector(std::vector<int> const& v1, std::vector<int> const& v2) {
		if (v1.size() != v2.size()) {
			Assert::Fail();
		}

		for (int i = 0, n = v1.size(); i < n; ++i) {
			if (v1[i] != v2[i]) {
				Assert::Fail();
			}
		}
	}

	TEST_METHOD(TestEmpty) {
		std::vector<int> input;
		std::vector<int> output;

		auto solution = Solution();
		auto result = solution.countSmaller(input);
		AssertVector(output, result);
	}

	TEST_METHOD(TestExample1) {
		std::vector<int> input = { 5, 2, 6, 1 };
		std::vector<int> output = { 2, 1, 1, 0 };

		auto solution = Solution();
		auto result = solution.countSmaller(input);
		AssertVector(output, result);
	}

	TEST_METHOD(TestDuplicates) {
		std::vector<int> input = { -1, -1 };
		std::vector<int> output = { 0, 0 };

		auto solution = Solution();
		auto result = solution.countSmaller(input);
		AssertVector(output, result);
	}
};
