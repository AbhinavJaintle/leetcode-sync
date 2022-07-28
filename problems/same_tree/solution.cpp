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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL||q==NULL){
            if(p==NULL&&q==NULL){
                return true;
            }
            else{
                return false;
            }
        }
        if(p->left==NULL&&p->right==NULL&&q->left==NULL&&q->right==NULL){
            if(p->val==q->val){
                return true;
            }
        }
        else{
            bool x = false;
            bool y = false;
            if(p->val==q->val){
                if(p->left!=NULL&&q->left!=NULL){
                    x = isSameTree(p->left, q->left);
                }
                else{
                    if(p->left==NULL&&q->left==NULL){
                        x = true;
                    }
                }
                if(p->right!=NULL&&q->right!=NULL){
                    y = isSameTree(p->right, q->right);
                }
                else{
                    if(p->right==NULL&&q->right==NULL){
                        y = true;
                    }
                }
            }
            return x&&y;
        }
        return false;
    }
};