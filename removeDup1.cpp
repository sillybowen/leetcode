class Solution {
  
public:
  int removeDuplicates(int A[], int n) {
    
    if (n==0) return 0;
    int start = 0;
    int i = 1;
    while (i<n) {
      
            if (A[i] != A[start] || 
                (start==0 || A[start-1]!=A[start])) {
              
              start++;
              A[start] = A[i];                    
            }
            i++;
    }
    return start+1;
  }
};
