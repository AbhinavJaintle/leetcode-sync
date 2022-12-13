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
    vector<TreeNode*> final = {};
public:
    void toSave(TreeNode*& root, vector<int>& to_delete, int flag){
        if(root==NULL){
            return;
        }
        for(auto&i:to_delete){
            if(root->val==i){
                    toSave(root->left,to_delete,0);
                    toSave(root->right,to_delete,0);
                    root=NULL;
                    return;
            }
        }
        if(flag==0){
            final.push_back(root);
        }
        toSave(root->left,to_delete,1);
        toSave(root->right,to_delete,1);
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        toSave(root,to_delete,0);
        return final;
    }
};