/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* a=head;
        ListNode* prev = nullptr;
        while(a!=nullptr )
        {
                    ListNode* b=a->next;

            a->next=prev;
            prev=a;
           a=b;
                   }
     return prev;
      

    }
};