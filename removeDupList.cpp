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
  ListNode *deleteDuplicates(ListNode *head) {
    
    if (head == NULL) return NULL;
    ListNode* tail = head;
    if (tail->next == NULL) return head;
    ListNode* tmp = tail->next;
    tail->next = NULL;
    while (tmp!=NULL) {
      
      if (tail->val!=tmp->val) {
        
        tail->next = tmp;
        tail = tmp;
        tmp = tmp->next;
        tail->next = NULL;
      }
      else {
        
        tmp = tmp->next;
      }
    }
    return head;
  }
};
