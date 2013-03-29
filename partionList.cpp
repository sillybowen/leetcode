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
  ListNode *partition(ListNode *head, int x) {
    
    ListNode * head1, * head2, *tail1,*tail2;
        
    ListNode * tmp = head;
        
    head1 = NULL;
    head2 = NULL;
    tail1 = NULL;
    tail2 = NULL;
    while (tmp!=NULL) {
      
      if (tmp->val<x) {
        
        if (head1 == NULL) {
           
          head1 = tmp;
          tail1 = tmp;
        }
        else {
          
          tail1->next = tmp;
          tail1 = tail1->next;
        }
      }
      else {
        
        if (head2 == NULL) {
          
          head2 = tmp;
          tail2 = tmp;
        }
        else {
          
          tail2->next = tmp;
          tail2 = tail2->next;
        }
      }
      tmp = tmp->next;
      if (tail1!=NULL) tail1->next = NULL;
      if (tail2!=NULL) tail2->next = NULL;
    } 
    if (tail1!=NULL) 
      tail1->next = head2;
    if (head1 == NULL)
      head1 = head2;
    return head1;
  }
};
