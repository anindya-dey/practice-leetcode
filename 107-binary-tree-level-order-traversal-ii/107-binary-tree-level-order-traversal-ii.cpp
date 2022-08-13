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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>> result;
        vector<int> temp;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        
        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            
            if(!node) {
                result.push_back(temp);
                if(!q.empty()) q.push(nullptr);
                temp = {};
            } else {
                temp.push_back(node->val);
                
                TreeNode *L = node->left;
                TreeNode *R = node->right;

                if(L) q.push(L);
                if(R) q.push(R);
            }
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
    
};