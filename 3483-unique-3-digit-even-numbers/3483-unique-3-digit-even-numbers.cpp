class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int, int> freq;
        for (int d : digits) {
            freq[d]++;
        }

        int count = 0;
        for (int num = 100; num <= 998; num += 2) {
            int d1 = num / 100;
            int d2 = (num / 10) % 10;
            int d3 = num % 10;

            unordered_map<int, int> temp;
            temp[d1]++;
            temp[d2]++;
            temp[d3]++;

            bool possible = true;
            for (auto& [digit, needed] : temp) {
                if (freq[digit] < needed) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                count++;
            }
        }

        return count;
    }
};