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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        map<int, vector<int>> m;
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        
        while(!q.empty()) {
            int size = q.size();
            map<int, multiset<int, less<int>>> mapset;

            while(size--) {
                auto p = q.front();
                q.pop();
                
                int x = p.first;
                TreeNode *node = p.second;
                
                mapset[x].insert(node->val);
                
                if(node->left) {
                    q.push({x-1, node->left});
                }
                
                if(p.second->right) {
                    q.push({x+1, node->right});
                }
            }
            
            for(auto i: mapset) {
                for(auto j: i.second) {
                    m[i.first].push_back(j);
                }
            }
        }
        
        for(auto coord: m) {
            res.push_back(coord.second);
        }
        
        return res;
    }
};