/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */

// @lc code=start
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
    int run(TreeNode *root, int &max_so_far)
    {
        if (!root)
            return 0;

        int l = max(run(root->left, max_so_far), 0);
        int r = max(run(root->right, max_so_far), 0);
        max_so_far = max(max_so_far, root->val + l + r);
        return root->val + max(l, r);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int max_so_far = INT_MIN;
        run(root, max_so_far);
        return max_so_far;
    }
};
// @lc code=end
