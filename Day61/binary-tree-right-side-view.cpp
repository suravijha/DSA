// LeetCode 199
// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *right = NULL;
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node)
                {
                    right = node;
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if (right)
            {
                ans.push_back(right->val);
            }
        }
        return ans;
    }
};