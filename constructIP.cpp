/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  TreeNode *dfs(vector<int> &inorder, vector<int> & postorder,
                int is,int ie, int ps,int pe) {
    if (ie<is || ps>pe) return NULL;
    if (is == ie) return new TreeNode(inorder[is]);
    int val = postorder[pe];
    int valI=-1;
    for (int i = is; i<=ie; i++)
      if (inorder[i] == val) {
        valI = i;
        break;
      }
    int leftCount = valI - is;
    int lis,lie,lps,lpe;
    int ris,rie,rps,rpe;
    lis = is;
    lie = valI -1;
    ris = valI +1;
    rie = ie;

    lps = ps;
    lpe = ps + leftCount -1;
    rps = lpe +1;
    rpe = pe -1;

    TreeNode* leftC = dfs(inorder,postorder,
                          lis,lie,lps,lpe);
    TreeNode* rightC =dfs(inorder,postorder,
                          ris,rie,rps,rpe);
    TreeNode* root = new TreeNode(val);
    root->left = leftC;
    root->right =rightC;
    return root;
  }
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {

    TreeNode* root = dfs(inorder,
                         postorder,
                         0,
                         inorder.size()-1,
                         0,
                         postorder.size()-1);
    return root;    
  }
};
