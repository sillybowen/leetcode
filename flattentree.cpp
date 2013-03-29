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
  
  void fl(TreeNode * node, TreeNode *& head, TreeNode *& tail) {
    
    if (node == NULL) {
      
      head = NULL;
      tail = NULL;
      return;
    }
    TreeNode * lefthead,*lefttail,*righthead,*righttail;
    fl(node->left,lefthead,lefttail);
    fl(node->right,righthead,righttail);
    node ->left = NULL;
    node->right = lefthead;
        
    if (lefttail == NULL) lefttail = node;
    lefttail->right = righthead;        
    head = node;
        
    tail = node;
    if (lefttail!=NULL)
      tail = lefttail;
    if (righttail!=NULL)
      tail = righttail;        
  }
public:
  void flatten(TreeNode *root) {
    
    TreeNode* head;
    TreeNode* tail;
    fl(root,head,tail);
  }
};
