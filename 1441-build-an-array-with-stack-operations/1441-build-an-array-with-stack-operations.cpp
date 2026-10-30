class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int targetIndex = 0;
        
        for(int i = 1; i <= n; i++) {
            // If we have already matched all elements in target, we can stop
            if(targetIndex == target.size()) break;
            
            ans.push_back("Push");
            
            if(i == target[targetIndex]) {
                targetIndex++; // Found the target element, move to next
            } else {
                ans.push_back("Pop"); // Not in target, push then pop
            }
        }
        
        return ans;
    }
};