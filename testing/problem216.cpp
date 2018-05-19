// 226. Invert Binary Tree
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	// It's just swapping the nodes. You can turn this into an
	// interative solution by using a queue or a stack (like all recursive solutions).
	void invert(TreeNode* node) {
		if (node == nullptr) {
			return;
		}

		invert(node->left);
		invert(node->right);
		std::swap(node->left, node->right);
	}

	TreeNode* invertTree(TreeNode* root) {
		invert(root);
		return root;
	}
};
