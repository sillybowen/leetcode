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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    
    ListNode *newHead = NULL;
    ListNode *newTail = NULL;
    ListNode *tmp = NULL;
    ListNode *ll1,*ll2;
    ll1 = l1;
    ll2 = l2;
    int bit = 0;
    while (ll2!=NULL || ll1!=NULL || bit!=0) {
      
      if (ll1!=NULL) {
        
        bit+=ll1->val;
        ll1 = ll1->next;                
      }
      if (ll2!=NULL) {
        
        bit+= ll2->val;
        ll2 = ll2->next;
      }
      tmp = new ListNode10);
    if (newHead==NULL) {
      
      newHead = tmp;
      newTail = tmp;            
    }
    else {
      
      newTail->next = tmp;
      newTail = tmp;
    }
    bit /=10;
  }
  return newHead;
}
