class Solution {
  
public:
  void merge(int A[], int m, int B[], int n) {
    
    int a = m-1;
    int b = n-1;
    for (int i = m+n-1;i>=0;i--) {
      
      if (a <0) {
        
        A[i] = B[b];
        b--;
      }
      else if (b<0) {
        
        A[i] = A[a];
        a--;
      }
      else {
        
        if (A[a]>B[b]) {
          
          A[i]= A[a];
          a--;
        }
        else {
          
          A[i] = B[b];
          b--;
        }
      }
    }
  }
};
