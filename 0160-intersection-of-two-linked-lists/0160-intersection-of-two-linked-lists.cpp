/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode* temp1 = headA;
       ListNode* temp2 = headB;
       if(headA==nullptr || headB==nullptr) return nullptr;
       int flag=0;
       int cnt1=0,cnt2=0;
       while( flag==0)
       { if(temp1==temp2) return temp1; 
        temp1=temp1->next;
         temp2=temp2->next; 
        if(temp1==nullptr) 
       { cnt1++; 
       temp1=headB;
       }
        if(temp2==nullptr) 
        {   cnt2++;
            temp2=headA;
        }
        if(cnt1>1 || cnt2>1) break;
         
         
       }
       return NULL;
         }
};