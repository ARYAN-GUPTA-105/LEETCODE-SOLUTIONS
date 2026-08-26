/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* node,int& ans){
        if(!node) return 0;
        int l = helper(node->left,ans), r = helper(node->right,ans);
        ans += abs(l) + abs(r);
        return node->val + l + r - 1;
    }
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        helper(root,ans);
        return ans;
    }
};