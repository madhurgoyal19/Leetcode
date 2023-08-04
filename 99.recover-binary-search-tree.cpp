/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
public:
    void recoverTree(TreeNode *root)
    {
        TreeNode *first, *mid, *last, *prev;
        first = mid = last = prev = nullptr;
        TreeNode *curr = root;
        while (curr)
        {
            if (!curr->left)
            {
                if (!prev || prev->val >= curr->val)
                {
                    if (!first)
                    {
                        first = prev;
                        mid = curr;
                    }
                    else
                        last = curr;
                }

                prev = curr;
                curr = curr->right;
            }
            else
            {
                TreeNode *now = curr->left;
                while (now->right && now->right != curr)
                {
                    now = now->right;
                }

                if (now->right == NULL)
                {
                    now->right = curr;
                    curr = curr->left;
                }
                else
                {
                    now->right = NULL;

                    if (!prev || prev->val >= curr->val)
                    {
                        if (!first)
                        {
                            first = prev;
                            mid = curr;
                        }
                        else
                            last = curr;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
        int k = first->val;
        if (!last)
        {
            first->val = mid->val;
            mid->val = k;
        }
        else
        {
            first->val = last->val;
            last->val = k;
        }
    }
};
// @lc code=end
