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
  vector<int> inorderTraversal(TreeNode *root) {
      
    stack<TreeNode*> q;
    vector<int> ans;
    if (root == NULL) return ans;
    TreeNode *  current = root;
        
        do {
          
          while (current!=NULL) {
            
            q.push(current);
            current = current->left;
          }
          current = q.top();
          q.pop();
          ans.push_back(current->val);
          current = current->right;            
        } while (!q.empty() || current!=NULL);
        return ans;
  }
};
