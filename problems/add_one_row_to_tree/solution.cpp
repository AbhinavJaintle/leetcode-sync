/* Definition for a binary tree node.
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
		///create root
        if(depth == 1){
            TreeNode *newRoot = new TreeNode(val, root, nullptr);
            return newRoot;
        }
        
        ///not root
        else{
            preorder(root, val, depth, 1);
        }
        return root;
    }
    
    void preorder(TreeNode* root, int val, int depth, int currDepth){
        if(!root)return;
        else if(currDepth == depth - 1){
            TreeNode *lnode = new TreeNode(val, root->left, nullptr);
            TreeNode *rnode = new TreeNode(val, nullptr, root->right);
            root->left = lnode;
            root->right = rnode;
            
            return;
        }
        else{
            preorder(root->left, val, depth, currDepth+1);
            preorder(root->right, val, depth, currDepth+1);
        }
    }
};