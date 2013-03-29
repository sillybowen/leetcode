class Solution {
  
  int bs(int A[], int start, int end, int target) {
    
    if (end-start<4) {
      
      for (int i = start; i<=end; i++)
        if (A[i] == target)
          return i;
      return -1;
    }        
    int mid = (start+end)/2;
    if (A[mid] == target) return mid;
        
    if (A[start]<A[mid]) {
      
      if (target<A[mid]&&target>=A[start]) {
        
        return bs(A,start,mid-1,target);
      }
    } else {
      
      if (target>=A[start] || target< A[mid])
        return bs(A,start,mid-1, target);            
    }
        
    return bs(A,mid+1,end,target);
  }
public:
  int search(int A[], int n, int target) {
    
    return bs(A,0,n-1,target);
  }
};
