/**
 * Definition for singly-linked list.
 * struct ListNode {
 
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {
 }
 * };
 */
class Solution {
  
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    
    ListNode*leftHead=head;
    ListNode*leftTail=NULL;
    ListNode*midHead;
    ListNode*midTail;
    int i = 1;
    ListNode*tmp=head;
    while(i<m) {
      
      leftTail = tmp;
      tmp = tmp->next;
      i++;
    }
    midHead = tmp;
    midTail = tmp;
    tmp = tmp->next;
    ListNode*tt;
    i++;
    while(i<=n) {
      
      tt = tmp;
      tmp = tmp->next;
      tt->next = midHead;
      midHead = tt;
      i++;
    }
    midTail->next = tmp;
    if (leftTail!=NULL)
      leftTail->next = midHead;
        
    if (leftTail == NULL) {
      
      return midHead;
    }
    return leftHead;
  }
};
