/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    int x;
    TreeNode *createTree(vector<int> &inorder, vector<int> &postorder, int start, int end)
    {
        if (start > end)
            return NULL;
        TreeNode *node = new TreeNode(postorder[x--]);
        int pos;
        for (int i = start; i <= end; i++)
        {
            if (inorder[i] == node->val)
            {
                pos = i;
                break;
            }
        }
        node->right = createTree(inorder, postorder, pos + 1, end);
        node->left = createTree(inorder, postorder, start, pos - 1);
        return node;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        x = postorder.size() - 1;
        return createTree(inorder, postorder, 0, inorder.size() - 1);
    }
};
// @lc code=end
