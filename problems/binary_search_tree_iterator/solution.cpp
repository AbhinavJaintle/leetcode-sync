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
class BSTIterator {
    int index=0;
    vector<int> v;
public:
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        return v[index++];
    }
    
    bool hasNext() {
        if(index==v.size())return false;

        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */