// LeetCode 111
// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

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
    bool isSymmetric(TreeNode *root)
    {
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode *n1, TreeNode *n2)
    {
        if (n1 == NULL && n2 == NULL)
        {
            return true;
        }
        if (n1 == NULL || n2 == NULL)
        {
            return false;
        }
        return n1->val == n2->val && isMirror(n1->left, n2->right) && isMirror(n1->right, n2->left);
    }
};