class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        auto canFormPrefix = [&](int len) {
            vector<int> temp = count;
            for (int i = 0; i < len; i++) {
                if (--temp[target[i] - 'a'] < 0) return false;
            }
            return true;
        };

        for (int i = n - 1; i >= 0; i--) {
            if (!canFormPrefix(i)) continue;

            vector<int> temp = count;
            for (int k = 0; k < i; k++) {
                temp[target[k] - 'a']--;
            }

            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (temp[c] > 0) {
                    temp[c]--;
                    string ans = target.substr(0, i);
                    ans += (char)('a' + c);
                    for (int ch = 0; ch < 26; ch++) {
                        while (temp[ch] > 0) {
                            ans += (char)('a' + ch);
                            temp[ch]--;
                        }
                    }
                    return ans;
                }
            }
        }

        return "";
    }
};