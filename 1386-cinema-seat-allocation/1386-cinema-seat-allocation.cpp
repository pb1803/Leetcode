class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> rows;

        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            rows[row] |= (1 << (s - 1));
        }


        int left   = 0b0000011110;
        int middle = 0b0001111000;
        int right  = 0b0111100000;

        int ans = (n - rows.size()) * 2;

        for (auto &[row, mask] : rows) {

            bool L = (mask & left) == 0;
            bool M = (mask & middle) == 0;
            bool R = (mask & right) == 0;

            if (L && R)
                ans += 2;
            else if (L || M || R)
                ans += 1;
        }

        return ans;
    }
};