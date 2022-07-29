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
    vector<int> v;
public:
    void preorder(TreeNode* root){
        if(root!=NULL){
            v.push_back(root->val);
            preorder(root->left);
            preorder(root->right);
        }
    }
    void flatten(TreeNode* root) {
        preorder(root);
        if(v.size()!=0){
          
          root->val = v[0];
          root->left = NULL;
          TreeNode* curr = root;
          root = curr;
          for(int i =1; i<v.size(); i++){
            TreeNode* temp = new TreeNode(v[i]);
            curr->right = temp;
            curr=temp;
          } 
        } 
    }
};