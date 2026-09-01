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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp=head;
        int cnt=0;
        if(head == nullptr || head->next == nullptr) return nullptr;
        while(fast!=nullptr && fast->next!=nullptr)
        { 
            if(cnt>0) temp=temp->next;
            slow=slow->next;
            fast=fast->next->next;
            cnt++;
            
        }
    temp->next=slow->next;
    return head;
    }
};