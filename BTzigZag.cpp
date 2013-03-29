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
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector< vector<TreeNode*> > a;
        vector<vector<int> > ans;
        if (root == NULL) return ans;
        vector<int> tmp;
        a.resize(2);
        int level = 0;
        a[0].push_back(root);
        while (a[level].size()!=0) {
            a[(level+1)%2].clear();            
            tmp.clear();
            for (int i = 0; i<a[level].size();i++) {
                tmp.push_back(a[level][i]->val);                
                if (a[level][i]->left!=NULL)
                    a[(level+1)%2].push_back(a[level][i]->left);
                if (a[level][i]->right!=NULL)
                    a[(level+1)%2].push_back(a[level][i]->right);
            }
        
            if (level == 1) {
                reverse(tmp.begin(),tmp.end());
            }      
            ans.push_back(tmp);
            level = (level+1)%2;
        }
        return ans;
    }
};