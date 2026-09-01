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
    bool hasCycle(ListNode *head) {
        map<ListNode* , int> mpp;
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            if(auto it = mpp.find(temp); it != mpp.end())
            {
                return true;
            }
            else 
            {
                mpp.insert({temp,1});
            }
            temp=temp->next;
        }
        return false;
    }
};