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
    vector<int> v={};
    void inorder(TreeNode* root, int curr){
        if(root==NULL){
            v.push_back(curr+1);
            return;
        }
        inorder(root->left,curr+1);
        inorder(root->right,curr+1);
    }
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL) return true;
        inorder(root,0);
        int prev=v[0];
        int flag=0;
        for(auto&i:v){
            if(flag==0){
                if(i!=prev){
                    if(i!=prev-1) return false;
                    else{
                        prev=i;
                        flag=1;
                    }
                }
            }
            if(flag==1){
                if(i!=prev) return false;
            }
        }
        return true;
    }
};