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
    int countGoodNodes(TreeNode* node, int limit) {
        if(!node) return 0;
        
        if(node->val >= limit) {
            return 1 + countGoodNodes(node->left, node->val) + countGoodNodes(node->right, node->val);
        }
        
        return countGoodNodes(node->left, limit) + countGoodNodes(node->right, limit);
    }

public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        
        return countGoodNodes(root, root->val);
    }
};