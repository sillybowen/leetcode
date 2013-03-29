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
  
  ListNode * merge(vector<ListNode *> * lists,int start,int end) {
    
    if (start>end) return NULL;
    if (start == end) return lists->at(start);
    int mid = (start+end)/2;
    ListNode * left = merge(lists,start,mid);
    ListNode * right = merge(lists,mid+1,end);      
    ListNode * newhead = NULL;
    ListNode * tmp = NULL;
    ListNode * tail = NULL;
    while (left!=NULL && right!=NULL) {
      
      if (left->val<right->val) {
        
        tmp = left;
        left = left->next;
      }
      else {
        
        tmp = right;
        right = right->next;
      }
      if (newhead == NULL) {
        
        newhead = tmp;
        tail = tmp;
      }
      else {
        
        tail->next = tmp;          
        tail = tail->next;
      }
    }
    if (left!=NULL) {
      
      if (newhead == NULL) return left;
      tail->next = left;
    }
    if (right!=NULL) {
      
      if (newhead == NULL) return right;
      tail->next = right;
    }
    return newhead;
  }
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    
    return merge(&lists,0,lists.size()-1);
  }
};
