/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    void createSum(TreeNode *root, int targetSum, vector<int> &sum, vector<vector<int>> &path)
    {
        if (!root)
            return;

        sum.push_back(root->val);
        if (!(root->left) && !(root->right) && targetSum == root->val)
        {
            path.push_back(sum);
        }

        createSum(root->left, targetSum - root->val, sum, path);
        createSum(root->right, targetSum - root->val, sum, path);
        sum.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> path;
        vector<int> sum;
        createSum(root, targetSum, sum, path);
        return path;
    }
};
// @lc code=end
