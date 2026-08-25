class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int mult = k;
        while (seen.count(mult)) {
            mult += k;
        }
        return mult;
    }
};