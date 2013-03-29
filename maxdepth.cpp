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
  
public:
  int maxDepth(TreeNode *root) {
    
    if(root == NULL) return 0;
    int leftdp = maxDepth(root->left);
    int rightdp = maxDepth(root->right);
    return leftdp>rightdp? leftdp+1:rightdp+1;
  }
};
