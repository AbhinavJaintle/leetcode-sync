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
vector<int> v;
class Solution {
public:
    void pre(TreeNode* root){
        if(root==NULL){
            return;
        }
        v.push_back(root->val);
        pre(root->left);
        pre(root->right);
        
    }
    void flatten(TreeNode* root) {
        v.clear();
        pre(root);
        if(v.size()!=0){
            root->left=NULL;
            TreeNode* curr = root;
            root=curr;
            for(int i = 1; i<v.size(); i++){
                TreeNode* temp = new TreeNode(v[i]);
                curr->right = temp;
                curr=temp;
            }
        }
    }
};