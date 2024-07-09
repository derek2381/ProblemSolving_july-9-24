// problem link
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/


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
public:
    void flattenTree(TreeNode* node, TreeNode*& prev) {
        if (node == nullptr) {
            return;
        }

        // Flatten the right subtree first
        flattenTree(node->right, prev);
        // Flatten the left subtree next
        flattenTree(node->left, prev);

        // Adjust the current node's pointers
        node->right = prev;
        node->left = nullptr;

        // Move the prev pointer to the current node
        prev = node;
    }
    void flatten(TreeNode* root) {
        if(root == nullptr){
            return ;
        }
        TreeNode* res = nullptr;
        flattenTree(root, res);
    }
};
