#include<cstring>
#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 */ struct ListNode {
   
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {
 }
 };
 
class Solution {
  
  void reverse(ListNode*& curHead,
               ListNode*& curTail) {
    ListNode * newHead;
    ListNode * newTail;
    ListNode * tmp = curHead->next;
    ListNode * tmp2;
    newTail = curHead;
    newHead = curHead;
    while(newHead!=curTail) {
      tmp2 = newHead;
      newHead = tmp;
      tmp = tmp->next;
      newHead ->next = tmp2;
    }
    curHead = newHead;
    curTail = newTail;
  }
  void reverse(ListNode*& curHead,
               ListNode*& curTail,
               ListNode*& newHead,
               ListNode*& LastTail) {
    reverse(curHead,curTail);
    if (newHead == NULL) {
      
      newHead = curHead;
    }
    else {
      
      LastTail->next = curHead;
    }
    LastTail = curTail;
    LastTail->next = NULL;
  }
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    
    if (k<2) return head;
    int count = 0;
    ListNode *curTail;
    ListNode *curHead = head;
    ListNode *newHead= NULL;
    ListNode *lastTail=NULL;
    ListNode *tmp = head;
    while (tmp!=NULL) {
      if (count==k) {
        
        count = 0;
        reverse(curHead,curTail,newHead,lastTail);
        curHead = NULL;
      }
      if (curHead == NULL) {
        
        curHead = tmp;                
      }
      curTail = tmp;
      tmp = tmp->next;
      count++;
    }
    if (count == k)
      reverse(curHead,curTail,newHead,lastTail);
    else if (lastTail==NULL) {
      
      return head;
    }
    else lastTail->next = curHead;
        
    return newHead;
  }
};

int main () {
  ListNode * n1 = new ListNode(1);
  ListNode *n2 = new ListNode(2);
  ListNode *n3 = new ListNode(3);
  ListNode *n4 = new ListNode(4);
  ListNode *n5 = new ListNode(5);
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  Solution s;
  n1 = s.reverseKGroup(n1,3);
  for (int i= 0;i<5;i++){
    cout<<n1->val<<endl;
    n1 = n1->next;
  }
}
