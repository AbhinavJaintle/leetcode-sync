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
    unordered_map<int,int> m;
    int curr;
public:
    TreeNode* build(int start, int end, vector<int>& inorder, vector<int>& postorder){
        if(start>end) return NULL;
        int temp=postorder[curr--];
        TreeNode* root = new TreeNode(temp);
        int n = m[temp];
        root->right=build(n+1,end,inorder,postorder);
        root->left=build(start,n-1,inorder,postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]]=i;
        }
        curr=inorder.size()-1;
        return build(0,inorder.size()-1,inorder,postorder);
    }
};