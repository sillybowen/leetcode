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
  
  bool traverse(TreeNode *p, TreeNode *q) {
    
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
        
    if (p->val!=q->val) return false;
    return traverse(p->left,q->left) && traverse(p->right,q->right);
  }
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    
    return traverse(p,q);
  }
};
