class Solution {
  
public:
  int maxSubArray(int A[], int n) {
    
    if (n == 0) return 0;
    int ans = A[0];
    int localMax = A[0];
    for (int i = 1; i<n; i++) {
      
      if (localMax<0)
        localMax = 0;
      localMax+= A[i];
      if (localMax>ans)
        ans = localMax;
    }
    return ans;
  }
};
