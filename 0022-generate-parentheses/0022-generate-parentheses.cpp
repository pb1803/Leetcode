class Solution {
public:
    void backtrack(int openN, int closedN, int n, string current, vector<string>& result) {
        if (openN == n && closedN == n) {
            result.push_back(current);
            return;
        }

        if (openN < n) {
            backtrack(openN + 1, closedN, n, current + "(", result);
        }

        if (closedN < openN) {
            backtrack(openN, closedN + 1, n, current + ")", result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(0, 0, n, "", result);
        return result;
    }
};