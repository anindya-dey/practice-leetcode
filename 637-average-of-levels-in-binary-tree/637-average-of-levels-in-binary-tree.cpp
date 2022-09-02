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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        
        double sum = 0;
        double count = 0;
        
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if(!curr) {
               
                double avg = sum / count;
                res.push_back(avg);
                sum = 0;
                count = 0;
                
                if(q.empty()) break;
                
                q.push(nullptr);
                continue;
            }
            
            sum += curr->val;
            count++;
            
            if(curr->left) {
                q.push(curr->left);
            }
            
            if(curr->right) {
                q.push(curr->right);
            }
        }
        
        return res;
    }
};