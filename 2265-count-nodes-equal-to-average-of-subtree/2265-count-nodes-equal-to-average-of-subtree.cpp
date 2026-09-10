class Solution {
    int matchingNodes = 0;

    pair<int, int> postOrder(TreeNode* node) {
        if (!node) return {0, 0};

        auto left = postOrder(node->left);
        auto right = postOrder(node->right);

        int currentSum = left.first + right.first + node->val;
        int currentCount = left.second + right.second + 1;

        if (node->val == currentSum / currentCount) {
            matchingNodes++;
        }

        return {currentSum, currentCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        postOrder(root);
        return matchingNodes;
    }
};