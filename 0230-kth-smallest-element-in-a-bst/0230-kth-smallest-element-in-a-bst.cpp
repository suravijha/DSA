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
private:
    void dfs(TreeNode* node, vector<int>& ans) {
        if (node == NULL)
            return;

        dfs(node -> left, ans);
        if (ans[0] == 0)
            return;

        ans[0]--;
        if (ans[0] == 0) {
            ans[1] = node -> val;
            return;
        }

        dfs(node -> right, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans(2);
        ans[0] = k;

        dfs(root, ans);
        
        return ans[1];
    }
};