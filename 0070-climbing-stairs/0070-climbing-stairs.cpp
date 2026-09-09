class Solution {
public:
    int climbStairs(int n) {
        int prev,prev2,curr;
        if(n==0) prev2=1;
        if(n==1) prev=1;
        for(int i=2;i<=n;i++)
        {
            curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
        
    }
};