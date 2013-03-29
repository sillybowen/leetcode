class Solution {
  
public:
  bool canJump(int A[], int n) {
    
    int maxV = 0;
    int i=0;
    while (i<=maxV&&maxV<n-1) {
      
      if (A[i]+i>maxV)
        maxV= A[i]+i;
      i++;
    }
    if (maxV>=n-1)
      return true;
    return false;
  }
};
