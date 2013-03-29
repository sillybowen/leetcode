class Solution {
  
public:
  int removeElement(int A[], int n, int elem) {
    
    int start = 0;
    int i = 0;
    while (i<n) {
      
      if (A[i] != elem) {
        
        A[start] = A[i];
        start++;
      }
      i++;
    }
    return start;
  }
};
