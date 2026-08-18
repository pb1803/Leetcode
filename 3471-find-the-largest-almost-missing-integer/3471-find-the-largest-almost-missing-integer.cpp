class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(nums.size()<k) return -1;
       if(nums.size() == k) {
            int largest = -1;
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] > largest) largest = nums[i];
            }
            return largest;
        }
        if(k == 1) {
            int largest = -1;
            for(int i = 0; i < nums.size(); i++) {
                int count = 0;
                for(int j = 0; j < nums.size(); j++) {
                    if(nums[i] == nums[j]) count++;
                }
                if(count == 1 && nums[i] > largest) {
                    largest = nums[i];
                }
            }
            return largest;
        }
        
        if(nums.size()>k)
        {
            int a,b;
            a=nums[0];
            b=nums[nums.size()-1];
            if(a==b) return -1;

            int cnt1=0,cnt2=0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==a) cnt1++;
                if(nums[i]==b) cnt2++;
            }
            if(cnt1==1 && cnt2==1)
            {
                if(a>b) return a;
                else return b;
            }
            else if(cnt1>1 && cnt2==1) return b;
            else if(cnt2>1 && cnt1==1) return a;
            else return -1;
        }
        return 0;
    }
};