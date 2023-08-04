/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool moveInTree(TreeNode *root, int currSum, int targetSum)
    {
        if (currSum == targetSum && root->left == NULL && root->right == NULL)
            return true;
        else if (root == NULL)
        {
            return false;
        }
        bool l, r;

        if (root->left)
        {
            l = moveInTree(root->left, currSum + root->left->val, targetSum);
        }
        if (root->right)
        {

            r = moveInTree(root->right, currSum + root->right->val, targetSum);
        }

        if (l || r)
            return true;
        else
            return false;
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return false;
        return moveInTree(root, root->val, targetSum);
    }
};
// @lc code=end
