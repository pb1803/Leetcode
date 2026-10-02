class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long XOR=0;
        for(int i=0;i<nums.size();i++)
        {
           XOR ^= nums[i];
        }
        int rightmost = (XOR & (XOR-1)) ^ XOR;
        int XOR1=0 , XOR2=0;
        for(int i=0;i<nums.size();i++)
        {
            if( nums[i] & rightmost)  XOR1 ^= nums[i];
            else XOR2 ^= nums[i];
        }
        return {XOR1,XOR2};
    }
};