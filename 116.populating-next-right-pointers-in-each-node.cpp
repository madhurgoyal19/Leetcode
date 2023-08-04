/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
#include <bits/stdc++.h>

class Solution
{
    void run(Node *root, vector<Node *> &level, int currLevel)
    {
        if (root == NULL)
            return;
        if (level.size() <= currLevel)
        {
            level.push_back(root);
        }
        else
        {
            level[currLevel]->next = root;
            level[currLevel] = root;
        }
        root->next = nullptr;

        run(root->left, level, currLevel + 1);
        run(root->right, level, currLevel + 1);
    }

public:
    Node *connect(Node *root)
    {
        vector<Node *> level;
        run(root, level, 0);
        return root;
    }
};
// @lc code=end
