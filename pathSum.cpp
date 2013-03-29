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
  
  bool dfs(TreeNode * root, int sum ,int ans) {
    
    if (root==NULL) {
      
      if (ans == sum) return true;
      else return false;
    }
    if (root->left == NULL && root->right == NULL) {
      
      if (ans + root->val == sum) return true;
      return false;
    }
        
    if (root->left!=NULL) {
      
      if (dfs(root->left,sum,ans+root->val))
        return true;
    }
    if (root->right!=NULL) {
      
      if (dfs(root->right,sum,ans+root->val))
        return true;
    }
    return false;
  }
public:
  bool hasPathSum(TreeNode *root, int sum) {
    
    if (root==NULL) return false;
    return dfs(root,sum,0);
  }
};
