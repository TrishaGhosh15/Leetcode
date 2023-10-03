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
    int helper(TreeNode* root,int maxi) {
        if(!root)
            return 0;  
        return root->val >= maxi ? 1 + helper(root->left,root->val) + helper(root->right,root->val) : helper(root->left,maxi) + helper(root->right,maxi) ;
    }
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        return helper(root,INT_MIN);    
    }
};