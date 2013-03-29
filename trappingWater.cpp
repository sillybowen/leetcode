class Solution {
  
public:
  int trap(int A[], int n) {
    
    int ans = 0;
    int h = 0;
    int cur = 0;
    int t = h+1;
    while (t<n) {
      
      if (A[t]<A[h]) cur+= A[h]-A[t];
      else {
        
        ans+=cur;
        h = t;
        cur = 0;
      }
      t++;
    }
    int mid = h;
    h = n-1;
    t = h-1;
    cur = 0;
    while (t>=mid) {
      
      if (A[t]<A[h]) cur+= A[h]-A[t];
      else {
        
        ans+=cur;
        h = t;
        cur = 0;
      }
      t--;
    }
    return ans;
        
  }
};
