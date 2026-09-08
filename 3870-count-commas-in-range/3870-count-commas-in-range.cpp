class Solution {
public:
    int countCommas(int n) {
        int cnt=0;
        int number=n;
        while(n>0)
        {
            cnt++;
            n=n/10;
        }
        if(cnt<=3) return 0;
        if(cnt==4 || cnt==5 || cnt==6)
        {
           int c=number-999;
           return c;

        }
        if(cnt==7)
        {
            int c=number-99999;
            return c*2;
        }
        return 0;
    }
};