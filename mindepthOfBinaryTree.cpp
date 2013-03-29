/**
 * Definition for binary tree
 * struct TreeNode {
 
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {
 }
 * };
 */
class Solution {
  
  void recFind(TreeNode * root, int dep, int &ans) {
    
    if (root->left == NULL && root->right==NULL){
      
      if (ans == -1||dep<ans)
        ans = dep+1;
      return;
    }
        
    if (root->left!=NULL) 
      recFind(root->left,dep+1,ans);
    if (root->right!=NULL) 
      recFind(root->right,dep+1,ans);
  }
public:
  int minDepth(TreeNode *root) {
    
    if (root == NULL) return 0;
    int ans= -1;
    recFind(root,0,ans);
    return ans;
  }
};
