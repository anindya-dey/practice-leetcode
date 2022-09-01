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
        
        int count = 0;
        
        if(node->val >= limit) {
            count = 1;
        }
        
        return count + countGoodNodes(node->left, max(node->val, limit)) + countGoodNodes(node->right, max(node->val, limit));
        
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        
        return countGoodNodes(root, root->val);
    }
};