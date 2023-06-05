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
class CBTInserter {
public:
    TreeNode* head = NULL;
    TreeNode* curr = NULL;

    int helper(TreeNode* root, int val){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(!temp->left||!temp->right){
                if(!temp->left){curr=temp;temp->left=new TreeNode(val);}
                else temp->right=new TreeNode(val);
                return temp->val;
            }
            q.push(temp->left);
            q.push(temp->right);
        }
        return -1;
    }
    
    CBTInserter(TreeNode* root) {
        head=root;
    }
    
    int insert(int val) {
        if(curr){
            curr->right=new TreeNode(val);
            int ans = curr->val;
            curr=NULL;
            return ans;
        }
        TreeNode* temp = head;
        return helper(temp,val);
    }
    
    TreeNode* get_root() {
        return head;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */