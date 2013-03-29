class Solution {
  
  int bs(int A[], int start, int end, int target) {
    
    if (end - start<5) {
      
      for (int i = start; i<=end; i++)
        if (A[i]>= target) 
          return i;
      return end + 1;
    }
    int mid = (start+end)/2;
        
    if (A[mid]>=target) return bs(A,start,mid,target);
    else return bs(A,mid+1,end,target);
  }
public:
  int searchInsert(int A[], int n, int target) {
    
    return bs(A,0,n-1,target);
  }
};
