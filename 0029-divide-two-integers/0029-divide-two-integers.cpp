class Solution {
public:
    int divide(int dd, int ds) {
        if(dd==ds) return 1;
        if(dd==INT_MIN && ds==-1) return INT_MAX;
        if(ds==1) return dd;
        long ans=0;
        long n=labs(long(dd));
        long d=labs(long(ds));
        bool isPositive = true;
        if(dd>=0 && ds<0) isPositive = false;
        if(ds>=0 && dd<0) isPositive = false;
        while(n>=d)
        {
            int cnt=0;
            
         while (n >= (d << (cnt + 1))) {
        cnt++;
              }
        ans += (1L << cnt);
          n -= (d << cnt);

        }
        
        return isPositive ? ans : -ans;
        
    }
};