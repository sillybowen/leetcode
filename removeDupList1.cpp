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
    
    ListNode *newHead=new ListNode(0);
    ListNode *tail = newHead;
    ListNode * tmp = head;
    while(tmp!=NULL) {
      
      if (tmp->next == NULL || tmp->val!= tmp->next->val) {
        
        tail->next = tmp;
        tmp = tmp->next;
        tail = tail->next;
        tail->next = NULL;
      }
      else {
        
        int v = tmp->val;
        while (tmp!=NULL&&tmp->val == v) {
          
          tmp = tmp->next;
        }
      }
    }
    return newHead->next;
  }
};
