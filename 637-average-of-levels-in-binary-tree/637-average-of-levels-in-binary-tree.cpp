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
        
        /*
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
        */
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            double sum = 0;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                
                sum += curr->val;
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            res.push_back(sum/(double)size);
        }
        
        return res;
    }
};