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
    string preorder(TreeNode* root, string temp){
        if(root==NULL){
            return temp;
        }
        if(root->left==NULL&&root->right==NULL){
            return to_string(root->val);
        }
        string curr;
        for(auto&i:to_string(root->val)){
         temp.push_back(i);
        }
        string s1 = preorder(root->left,curr);
        // if(s1.length()!=0){
        temp.push_back('(');
        for(auto&i:s1){
            temp.push_back(i);
        }
        temp.push_back(')');
        // }
        string s2 = preorder(root->right,curr);
        if(s2.length()!=0){
        temp.push_back('(');
        for(auto&i:s2){
            temp.push_back(i);
        }
        temp.push_back(')');
        }
        return temp;
    }
    string tree2str(TreeNode* root) {
        string temp;
        return preorder(root,temp);
    }
};