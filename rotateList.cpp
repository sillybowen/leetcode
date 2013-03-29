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
  
  int count1(ListNode * head,ListNode *& tail) {
    
    int ret = 0;
    while (head!=NULL) {
      
      ret++;
      tail = head;
      head = head->next;
    }
    return ret;
  }
  void getKth(ListNode * head, ListNode *& pre,int c) {
    
    int cc = 1;
    pre = head;
    while (cc<c) {
      
      pre = pre->next;
      cc++;
    }
  }
public:
  ListNode *rotateRight(ListNode *head, int k) {
    
    ListNode * pre;
    ListNode * kth;
    ListNode * tail;
    int count = count1(head,tail);
    if (count<2) return head;
    if count == 0) return head;
  getKthcount);
        
kth = pre->next;
pre->next = NULL;
tail ->next = head;
return kth;        
}
};
