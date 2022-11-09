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
class FindElements {
    unordered_map<int,int> m;
    void search(TreeNode* root){
        if(root->right==NULL&&root->left==NULL){
            return;
        }
        if(root->right!=NULL){
            root->right->val = 2*root->val+2;
            m[root->right->val]++;
            search(root->right);
        }
        if(root->left!=NULL){
            root->left->val = 2*root->val+1;
            m[root->left->val]++;
            search(root->left);
        }
    }
public:
    FindElements(TreeNode* root) {
        m.clear();
        root->val=0;
        m[0]++;
        search(root);
    }
    
    bool find(int target) {
        return m[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */