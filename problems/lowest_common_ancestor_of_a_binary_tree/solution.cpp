/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL){
            return false;
        }
        if(root==p||root==q){
            return true;
        }
        return helper(root->left,p,q)||helper(root->right,p,q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p||root==q){
            return root;
        }
        bool t1 = helper(root->left,p,q);
        bool t2 = helper(root->right,p,q);
        if(t1&&t2){
            return root;
        }
        if(t1){
            return lowestCommonAncestor(root->left,p,q);
        }
        return lowestCommonAncestor(root->right,p,q);
    }
};