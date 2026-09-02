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

    ListNode* findmiddle(ListNode* head)
    {
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    ListNode* merge2List(ListNode* list1, ListNode* list2)
    {
        ListNode* dummynode = new ListNode(-1);
        ListNode* temp = dummynode;
        while(list1 != nullptr && list2!=nullptr)
        {
            if(list1->val<list2->val) 
            {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else 
            {
                  temp->next = list2;
                temp = list2;
                list2 = list2->next;

            }
        }
        if(list1) temp->next = list1;
        else temp->next=list2;

        return dummynode->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;

        ListNode* middle = findmiddle(head);
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);
        return merge2List(left, right);
    }
};