class Solution {
public:
 vector<vector<int>> a;
    vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    ans.push_back({});
    for(int i=0;i<nums.size();i++)
    {
        int c=ans.size();
        for(int j=0;j<c;j++)
        {
            vector<int> temp=ans[j];
            temp.push_back(nums[i]);
            ans.push_back(temp);
        }
    }
    return ans;
        
    }
};