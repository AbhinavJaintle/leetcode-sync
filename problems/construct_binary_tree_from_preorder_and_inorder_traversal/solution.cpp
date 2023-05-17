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
    TreeNode* helper(int& index, int left, int right, vector<int>& preorder, vector<int>& inorder){
        if(index==inorder.size()||left==right)return NULL;
        int p = -1;
        for(int i = left; i<right; i++){
            if(inorder[i]==preorder[index]){
                p=i;
                break;
            }
        }
        if(p==-1)return NULL;
        TreeNode* root = new TreeNode(preorder[index]);
        index++;
        root->left = helper(index,left,p,preorder,inorder);
        root->right = helper(index,p+1,right,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int s = 0;
        return helper(s,0,preorder.size(),preorder,inorder);
    }
};