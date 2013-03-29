class Solution {
  
public:
  int jump(int A[], int n) {
    
    vector<int> ans;
    ans.resize(n,-1);
    ans[0] = 0;
    for (int i = 0; i<n;i++) 
      if (ans[i]>=0) 
        if (i==0 || A[i]+1>A[i-1]) 
          for (int j = 1; j<=A[i];j++)
            if (i+j<n && (ans[i+j] == -1 || ans[i+j]>ans[i]+1))
              ans[i+j] = ans[i]+1;
                      
    return ans[n-1];
  }
};
