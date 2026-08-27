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

    ListNode* reverse(ListNode* head)
    {
        if(head==nullptr ||  head->next==nullptr) return head;
        ListNode* newhead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;
        return newhead;

    }
     

    bool isPalindrome(ListNode* head) {
    // Brute Force Approach
    //     stack<int> st;
    //     ListNode* temp= head;
    //     while(temp!=nullptr)
    //     {
    //         st.push(temp->val);
    //         temp=temp->next;
    //     }
    //     ListNode* temp1=head;
    //     while(temp1!=nullptr)
    //     {
    //         int a = st.top();
    //         if(a==temp1->val)
    //         {
    //             st.pop();
    //             temp1=temp1->next;
    //             continue;
    //         }
    //         else return false;
    //     }

    //   return true;


    // Optimal Approach - 
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        
    } 
    ListNode* newhead = reverse(slow->next);
    ListNode* first = head;
    ListNode* second = newhead;
    while(second!=NULL)
    {
        if(first->val!=second->val)
        {
            reverse(newhead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverse(newhead);
    return true;

     }
};