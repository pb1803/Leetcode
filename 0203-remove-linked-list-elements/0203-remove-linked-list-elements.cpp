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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp!=nullptr)
        {
            if(temp->val == val)
            {
              if(prev!=nullptr) 
              { prev->next = temp->next;
              
              }
              else
              {
                head=temp->next;
                
              }
              temp=temp->next;

              
            }
            else 
            {  prev = temp;
                temp=temp->next;
            }
        }
        return head;
    }
};