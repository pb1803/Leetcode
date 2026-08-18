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
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        int carry=0;

        ListNode* dummynode = new ListNode(-1);
        ListNode* curr=dummynode;
        while(head1!=nullptr || head2!=nullptr)
        {   int sum = carry;
            if(head1) sum += head1->val;
            if(head2) sum += head2->val;
            ListNode* newnode = new ListNode(sum%10);
            carry = sum/10;
            curr->next=newnode;
            curr=curr->next;
            if(head1) head1=head1->next;
            if(head2) head2=head2->next;
            if(carry)
            {
                curr->next=new ListNode(carry);
            }
            
        }
        return dummynode->next;
    }
};