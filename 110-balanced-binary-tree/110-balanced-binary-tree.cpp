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
    pair<int, bool> checkHeightDiff(TreeNode* node) {
        if(!node) return make_pair(0, true);
        
        auto left = checkHeightDiff(node->left);
        auto right = checkHeightDiff(node->right);
        
        bool isLeftBalanced = left.second;
        bool isRightBalanced = right.second;
        bool isCurrBalanced = abs(left.first - right.first) <= 1;
        
        int currHeight = max(left.first, right.first) + 1;
        
        return make_pair(currHeight, isLeftBalanced && isRightBalanced && isCurrBalanced);
        
    }
public:
    bool isBalanced(TreeNode* root) {
        auto ans = checkHeightDiff(root);
        return ans.second;
    }
};