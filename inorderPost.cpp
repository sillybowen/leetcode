/**
 * Definition for binary tree
 * /
struct TreeNode {
 
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {
 }
  };
 */
#include <vector>
#include<iostream>
#include <set>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {
 }
};

class Solution {
  TreeNode *dfs(vector<int> &inorder, vector<int> & postorder,
                int is,int ie, int ps,int pe) {
    cout<<is<<' '<<ie<<" "<<ps<<' '<<pe<<endl;
    if (ie<is || ps>pe) return NULL;
    if (is == ie) return new TreeNode(inorder[is]);
    int val = postorder[pe];
    int valI=-1;
    set<int> left;
    for (int i = is; i<=ie; i++)
      if (inorder[i] == val) {
        valI = i;
        break;
      }
      else left.insert(inorder[i]);
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

int main() {
  vector<int>in;
  vector<int>po;
  in.push_back(1);
  in.push_back(3);
  in.push_back(2);
  po.push_back(3);
  po.push_back(2);
  po.push_back(1);
  Solution s;
  s.buildTree(in,po);
}
