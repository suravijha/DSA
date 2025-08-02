// LeetCode 110
// Given a binary tree, determine if it is height-balanced.

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
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return solve(root).first;
    }

private:
    pair<bool, int> solve(TreeNode *root)
    {
        if (root == NULL)
            return {true, 0};
        pair<bool, int> left = solve(root->left);
        pair<bool, int> right = solve(root->right);
        bool balance = left.first && right.first && abs(left.second - right.second) <= 1;
        return {balance, 1 + max(left.second, right.second)};
    }
};