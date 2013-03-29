class Solution {

public:
  int firstMissingPositive(int A[], int n) {
    int i = 0;
    int j,q;
    while (i<n) {
      j = A[i];
      while (j>0 && j<=n && A[j-1]!=j) {
        q = A[j-1];
        A[j-1] = j;
        j = q;
      }
      i++;
    }
    int ans =1 ;
    while (A[ans-1]==ans)
      ans++;
    return ans;
  }
};
