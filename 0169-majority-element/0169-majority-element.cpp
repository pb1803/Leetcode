class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(cnt==0)
            {
                cnt=1;
                element = nums[i];
            }
            else if(nums[i]==element) cnt++;
            else 
            { cnt--;
            }
        }
        int cnt1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==element) cnt1++;
        }
        return element;
          }
};