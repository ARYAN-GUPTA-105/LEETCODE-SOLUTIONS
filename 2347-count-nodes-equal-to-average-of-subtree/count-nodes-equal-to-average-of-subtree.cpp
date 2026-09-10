/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    pair<int, int> helper(TreeNode* root) {
        if (!root)
            return {0, 0};
        auto leftsum = helper(root->left);
        auto rightsum = helper(root->right);
        int num = leftsum.second + rightsum.second + 1;
        if (root->val == (root->val + leftsum.first + rightsum.first) / num)
            ans++;
        return {root->val + leftsum.first + rightsum.first, num};
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return ans;
    }
};