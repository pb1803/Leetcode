class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int cnt= (1<<(nums.size()));
        for(int val=0;val<cnt;val++)
        {
            vector<int> subset;
            for(int i=0;i<nums.size();i++)
            {
                if(val & (1<<i)) subset.push_back(nums[i]);
            }
            ans.push_back(subset);

        }
        set<vector<int>> st;
        for(int i=0;i<ans.size();i++)
        {
            st.insert(ans[i]);
        }
return vector<vector<int>>(st.begin(), st.end());    }
};