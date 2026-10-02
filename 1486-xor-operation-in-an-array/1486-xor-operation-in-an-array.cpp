class Solution {
private:
    int XORtillN(int n) {
        if (n <= 0) return 0; // Fixes negative inputs like XORtillN(-1)
        if (n % 4 == 1) return 1;
        if (n % 4 == 2) return n + 1;
        if (n % 4 == 3) return 0;
        return n;
    }

public:
    int xorOperation(int n, int start) {
        int s = start / 2;
        int xor_sum = XORtillN(s - 1) ^ XORtillN(s + n - 1);
        
        int result = xor_sum << 1;
        
        if ((start & 1) && (n & 1)) {
            result |= 1;
        }
        
        return result;
    }
};