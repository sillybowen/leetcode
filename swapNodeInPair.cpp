**
 * Definition for singly-linked list.
  * struct ListNode {

    *     int val;
    *     ListNode *next;
    *     ListNode(int x) : val(x), next(NULL) {
    }
    * };
 */
 class Solution {

   void swap(ListNode *& pre, ListNode *& n1, ListNode *& n2) {

     if(pre!=NULL)
       pre->next = n2;
     n1->next = n2-> next;
     n2->next = n1;
   }
 public:
   ListNode *swapPairs(ListNode *head) {

     ListNode* pre,*n1,*n2;
     int count = 0;
     ListNode* newHead=NULL;
     pre = NULL;
     n1 = head;
     while (n1!=NULL) {

       n2 = n1->next;
       if (n2!=NULL) {

         swap(pre,n1,n2);
         if (newHead == NULL)
           newHead = n2;
         pre = n1;
         n1 = n1->next;
       }
       else {

         if (newHead == NULL)
           newHead = n1;
         n1 = NULL;
       }
     }
     return newHead;
   }
 };1;2c/**
        * Definition for singly-linked list.
        * struct ListNode {
        
        *     int val;
        *     ListNode *next;
        *     ListNode(int x) : val(x), next(NULL) {
        }
        * };
        */
class Solution {
   
   void swap(ListNode *& pre, ListNode *& n1, ListNode *& n2) {
     
     if(pre!=NULL)
       pre->next = n2;
     n1->next = n2-> next;
     n2->next = n1;
   }
 public:
   ListNode *swapPairs(ListNode *head) {
     
     ListNode* pre,*n1,*n2;
     int count = 0;
     ListNode* newHead=NULL;
     pre = NULL;
     n1 = head;
     while (n1!=NULL) {
       
       n2 = n1->next;
       if (n2!=NULL) {
         
         swap(pre,n1,n2);
         if (newHead == NULL)
           newHead = n2;
         pre = n1;
         n1 = n1->next;
       }
       else {
         
         if (newHead == NULL)
           newHead = n1;
         n1 = NULL;
       }
     }
     return newHead;
   }
 };
