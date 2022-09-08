class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		if(!root) return NULL;
		root->left=deleteNode(root->left,key);
		root->right=deleteNode(root->right,key);
		if(root->val==key) {
			if(!root->right) return root->left;
			TreeNode* cur=root->right;
			while(cur->left) cur=cur->left;
			cur->left=root->left;
			return root->right;
		}
		return root;
	}
};