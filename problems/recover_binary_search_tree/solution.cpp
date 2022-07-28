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
    vector<int> v = {};
public:
    void inorder(TreeNode* p){
        if(p!=NULL){
            inorder(p->left);
            v.push_back(p->val);
            inorder(p->right);
        }
    }
    void create(TreeNode* p){
        if(p!=NULL){
            create(p->left);
            p->val = *(v.end()-1);
            v.pop_back();
            create(p->right);
        }
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        sort(v.begin(),v.end(),greater<int>());
        create(root);
    }
};