/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {
 }
 * };
 */
class Solution {
  
  void dfs(TreeLinkNode * root, vector<TreeLinkNode *> &levelNode, int depth) {
    
    if (root == NULL) return;
        
    if (levelNode.size()<=depth) {
      
      levelNode.push_back(root);
      root->next = NULL;
    }
    else {
      
      levelNode[depth]->next = root;
      levelNode[depth] = root;
      root->next = NULL;
    }
    dfs(root->left,levelNode,depth+1);
    dfs(root->right,levelNode,depth+1);
  }
public:
  void connect(TreeLinkNode *root) {
    
    vector<TreeLinkNode *> levelNode;
    dfs(root, levelNode, 0);        
  }
};
