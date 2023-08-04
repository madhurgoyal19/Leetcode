/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sum = 0;
    void startSum(TreeNode *root, int prevSum)
    {
        if (!root)
            return;

        prevSum = prevSum + root->val;

        if (root->left == NULL && root->right == NULL)
        {
            sum += prevSum;
        }
        else
        {
            startSum(root->left, prevSum * 10);
            startSum(root->right, prevSum * 10);
        }
    }

public:
    int sumNumbers(TreeNode *root)
    {
        startSum(root, 0);
        return sum;
    }
};
// @lc code=end
