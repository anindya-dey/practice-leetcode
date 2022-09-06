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
    bool containsOne(TreeNode* node) {
        if(!node) return false;
        
        bool left = containsOne(node->left);
        bool right = containsOne(node->right);
        
        if(!left) {
            node->left = nullptr;
        }
        
        if(!right) {
            node->right = nullptr;
        }
        
        if(node->val == 1) return true;
        
        return left || right;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        bool res = containsOne(root);
        return res ? root : nullptr;
    }
};