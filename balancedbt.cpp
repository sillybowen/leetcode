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
  bool check(TreeNode *node, int &degree) {
    
    if (node == NULL) return true;
        
    int leftdegree;
    int rightdegree;
    bool ret = true;
    if (node->left == NULL) {
      
      leftdegree = 0;
    }
    else 
      ret = ret && check(node->left,leftdegree);
    if (node->right == NULL) {
      
      rightdegree = 0;
    }
    else 
      ret = ret && check(node->right,rightdegree);
    if ( leftdegree-rightdegree>1 || leftdegree-rightdegree<-1)
      ret = false;
    if (leftdegree>rightdegree)
      degree = leftdegree+1;
    else
      degree = rightdegree+1;
            
    return ret;
  }
  bool isBalanced(TreeNode *root) {
    
    int x;
    return check(root,x);
  }
};
