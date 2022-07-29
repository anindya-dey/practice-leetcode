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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        
        TreeNode *curr = root;
        stack<TreeNode*> s;
        s.push(curr);
        
        while(!s.empty()) {
            TreeNode *temp = s.top();
            s.pop();
            
            result.push_back(temp->val);
            
            if(temp->right) s.push(temp->right);
            
            if(temp->left) s.push(temp->left);
        }
        
        return result;
    }
};