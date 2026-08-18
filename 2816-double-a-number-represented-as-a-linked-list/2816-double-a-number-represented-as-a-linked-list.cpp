class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        
        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int carry = 0;
        vector<int> result;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int doubled = arr[i] * 2 + carry;
            result.push_back(doubled % 10);
            carry = doubled / 10;
        }
        if (carry > 0) {
            result.push_back(carry);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;
        for (int i = result.size() - 1; i >= 0; i--) {
            ans->next = new ListNode(result[i]);
            ans = ans->next;
        }

        return dummy->next;
    }
};