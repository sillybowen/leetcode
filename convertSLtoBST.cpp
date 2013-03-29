/**
 * Definition for singly-linked list.
 * struct ListNode {
 
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {
 }
 * };
 */
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
  
  TreeNode * dfs(ListNode *& node, int head, int tail) {
    
    if (head>tail) return NULL;
    int mid = (head+tail)/2;
    TreeNode * left = dfs(node,head,mid-1);
    TreeNode* ret = new TreeNode(node->val);
    node = node->next;
    TreeNode * right = dfs(node,mid+1,tail);
    ret->left = left;
    ret->right = right;
    return ret;
  }
public:
  TreeNode *sortedListToBST(ListNode *head) {
    
    int len = 0;
    if (head == NULL) return NULL;
    ListNode *tmp = head;
    while (tmp->next!=NULL) {
      
      len++;
      tmp = tmp->next;
    }
    tmp = head;
    return dfs(tmp,0,len);
  }
};
