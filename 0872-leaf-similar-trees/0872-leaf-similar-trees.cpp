class Solution {
public:
    void leaves(vector<int> &leaf,TreeNode* node) {
        if(node->left==nullptr and node->right==nullptr) {
            leaf.push_back(node->val);
            return;
        }
        if(node->left!=nullptr) leaves(leaf,node->left);
        if(node->right!=nullptr) leaves(leaf,node->right);
    }
    bool checkleaves(vector<int> &leaf,int &i,TreeNode* node) {
        if(i>=leaf.size() or node==nullptr) return false;
        if(node->left==nullptr and node->right==nullptr){
            if(leaf[i]==node->val){
                i++;
                return true;
            }
            return false;
        }
        if(node->right==nullptr) return (checkleaves(leaf,i,node->left));
        if(node->left==nullptr) return (checkleaves(leaf,i,node->right)); 
        return (checkleaves(leaf,i,node->left) and checkleaves(leaf,i,node->right));
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf;
        leaves(leaf,root1);
        int i=0;
        bool f = checkleaves(leaf,i,root2);
        return (f and i==leaf.size());  
    }
};