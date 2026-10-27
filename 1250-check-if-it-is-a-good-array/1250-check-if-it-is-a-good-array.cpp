class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        if(nums.size()==1) 
        {
            if(nums[0]==1) return true;
            else return false;
            
        } 
        int gcdd = gcd(nums[0],nums[1]) ;

        for(int i=2;i<nums.size();i++)
        {
            gcdd = gcd(gcdd,nums[i]);
        }
        if(gcdd==1) return true;
        else return false;
    }
    
};