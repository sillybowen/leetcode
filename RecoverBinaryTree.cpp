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
  
  void dfs(TreeNode *root, 
           TreeNode *&last, 
           TreeNode *& n1, 
           TreeNode * &n2) {
    
    if (root == NULL) return;
    dfs(root->left,last,n1,n2);            
    if (last!=NULL && last->val>root->val) {
      
      if (n1==NULL) {
        
        n1 = last;
      }
      n2 = root;
    }
    last = root;
    dfs(root->right,last,n1,n2);        
  }
public:
  void recoverTree(TreeNode *root) {
      
    TreeNode *n1 = NULL;
    TreeNode *n2 = NULL;
    TreeNode *last = NULL;
    dfs(root,last,n1,n2);
    if (n1!=NULL && n2!=NULL) {
      
      int p = n1->val;
      n1->val = n2->val;
      n2->val = p;
    }
  }
};
