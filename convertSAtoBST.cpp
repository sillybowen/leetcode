/**
 * Definition for binary tree
 * struct TreeNode {
 
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     Tre
 * eNode(int x) : val(x), left(NULL), right(NULL) {
 }
 * };
 */
class Solution {
  
  TreeNode* dfs(vector<int>&num, int start,int end) {
    
    if (start > end) return NULL;
    int mid = (start+end)/2;
    TreeNode* ret = new TreeNode(num[mid]);
    ret->left = dfs(num,start,mid-1);
    ret->right = dfs(num,mid+1,end);
    return ret;
  }
public:
  TreeNode *sortedArrayToBST(vector<int> &num) {
    
    TreeNode*ans = dfs(num,0,num.size()-1);
    return ans;
  }
};
