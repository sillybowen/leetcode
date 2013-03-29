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
private:
  void traverse(TreeNode *root,int &singlePath,int &doublePath,int &ans) {
    if (root == NULL) {
      singlePath = -10000000;
      doublePath = -10000000;
      return;
    }
    int leftSingle,rightSingle,leftDouble,rightDouble;
    traverse(root->left,leftSingle,leftDouble,ans);
    traverse(root->right,rightSingle,rightDouble,ans);

    if (root->val>ans) ans = root->val;

    doublePath = root->val;
    singlePath = root->val;

    if (leftSingle>ans) ans = leftSingle;
    if (rightSingle>ans) ans = rightSingle;
    if (leftDouble>ans) ans = leftDouble;
    if (rightDouble>ans) ans = rightDouble;


    if (leftDouble>doublePath)
      doublePath = leftDouble;
    if (rightDouble>doublePath)
      doublePath = rightDouble;
    if (leftSingle+rightSingle+root->val>doublePath)
      doublePath = leftSingle+rightSingle+root->val;

    if (leftSingle+root->val>singlePath)
      singlePath = leftSingle+root->val;
    if (rightSingle+root->val>singlePath)
      singlePath = rightSingle+root->val;

    if (doublePath>ans) ans = doublePath;
    if (singlePath>ans) ans = singlePath;
  }
public:
  int maxPathSum(TreeNode *root) {
    int ans;
    int singlePath,doublePath;
    if (root!=NULL) ans = root->val;
    else return 0;

    traverse(root,singlePath,doublePath,ans);
    return ans;
  }
};
