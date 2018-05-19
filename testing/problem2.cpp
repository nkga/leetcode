// 2. Add Two Numbers
struct ListNode {
	int val;
	ListNode* next;

	ListNode(int x) : val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		auto head = new ListNode(0);
		auto node1 = l1;
		auto node2 = l2;
		auto output = head;
		int carry = 0;

		while (node1 || node2) {
			auto value1 = node1 ? node1->val : 0;
			auto value2 = node2 ? node2->val : 0;
			auto digit = value1 + value2 + carry;

			carry = digit / 10;
			
			output->next = new ListNode(digit % 10);
			output = output->next;

			node1 = node1 ? node1->next : nullptr;
			node2 = node2 ? node2->next : nullptr;
		}

		if (carry > 0) {
			output->next = new ListNode(carry);
		}

		return head->next;
	}
};
