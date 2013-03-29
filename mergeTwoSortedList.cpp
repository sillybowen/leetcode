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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    
    ListNode * newHead = NULL;
    ListNode * tail = NULL;
    ListNode * tmp;
    while (l1!=NULL && l2!=NULL) {
      
      if (l1->val<l2->val) {
        
        tmp = l1;
        l1 = l1->next;
      }
      else {
        
        tmp = l2;
        l2 = l2->next;
      }
      if (newHead == NULL) {
        
        newHead = tmp;
        tail = tmp;
      }
      else {
        
        tail->next = tmp;
        tail = tmp;
      }
    }
        
    if (l1!=NULL) {
      
      if (newHead == NULL) {
        
        newHead = l1;
      }
      else {
        
        tail->next = l1;
      }
    }
        
    if (l2!=NULL) {
      
      if (newHead == NULL) {
        
        newHead = l2;
      }
      else {
        
        tail->next = l2;
      }            
    }
    return newHead;
  }
};
