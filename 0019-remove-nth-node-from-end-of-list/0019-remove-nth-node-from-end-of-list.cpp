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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            cnt++;
            temp=temp->next;
        }
        if (cnt == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        int k=cnt-n;
        ListNode* temp1=head;
        for(int i=0;i<k-1;i++)
        {
            temp1=temp1->next;
        }
        ListNode* dele = temp1->next;
        temp1->next=temp1->next->next;
         dele->next=nullptr;
         delete dele;
         return head;
    }
};