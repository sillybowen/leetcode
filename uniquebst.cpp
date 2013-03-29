class Solution {
  
public:
  int numTrees(int n) {
    
    vector<int>ans;
    ans.resize(n+1);
    ans[0] = 1;
    ans[1] = 1;
    for (int i = 2;i<=n; i++){
      
      ans[i] = 0;
      for (int j = 0;j<=i-1;j++)
        ans[i]+= ans[j]*ans[i-1-j];
    }
    return ans[n];
  }
};
