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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    
    ListNode * startPrev=NULL;
    ListNode * start = head;
    ListNode * move = head;
    for (int i = 1;i<n;i++) {
      
      move = move->next;
    }
    while (move->next!=NULL) {
      
      move = move->next;
      startPrev = start;
      start = start->next;
    }
    if (startPrev == NULL) return head->next;
    startPrev->next = start->next;
    return head;
  }
};
