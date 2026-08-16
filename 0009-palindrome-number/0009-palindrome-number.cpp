class Solution {
public:
    bool isPalindrome(int x) {
        bool r;
        int revn = 0 ;
        int v = x;
        while (v != 0)
        {
          int ld = v%10;
           // overflow check BEFORE multiplication
            if (revn > INT_MAX / 10 || (revn == INT_MAX / 10 && ld > 7))
                return 0;
            if (revn < INT_MIN / 10 || (revn == INT_MIN / 10 && ld < -8))
                return 0;
          revn = revn*10 + ld;
          v = v/10; 

        }
        if (revn==x && x>0 || x==0 )
        {
            r = true ; 
        }
        else {
            r = false;
        }
        return r;
    }
};