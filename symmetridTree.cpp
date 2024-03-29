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
  
  bool mirror(TreeNode * left, TreeNode * right) {
    
    if (left == NULL && right == NULL) return true;
    if (left == NULL || right == NULL) return false;
    if (left->val!=right->val) return false;
        
    return mirror(left->left,right->right) && 
      mirror(left->right,right->left);
  }
public:
  bool isSymmetric(TreeNode *root) {
    
    if (root == NULL) return true;
    return mirror(root->left,root->right);
  }
};
