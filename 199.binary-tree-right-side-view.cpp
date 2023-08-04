/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    void run(TreeNode *root, vector<int> &a, int level)
    {
        if (root == NULL)
            return;
        if (level >= a.size())
            a.push_back(root->val);
        run(root->right, a, level + 1);
        run(root->left, a, level + 1);
    }

public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> answer;
        run(root, answer, 0);
        return answer;
    }
};
// @lc code=end
