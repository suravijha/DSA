// LeetCode 572
// Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
// A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. 
// The tree tree could also be considered as a subtree of itself.

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
private:
    bool isIdentical(TreeNode *node1, TreeNode *node2)
    {
        if (node1 == NULL && node2 == NULL)
        {
            return true;
        }
        if (node1 == NULL || node2 == NULL || node1->val != node2->val)
        {
            return false;
        }
        return isIdentical(node1->left, node2->left) && isIdentical(node1->right, node2->right);
    }

public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (subRoot == NULL)
            return true;
        if (root == NULL)
            return false;
        if (isIdentical(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};