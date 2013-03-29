class Solution {
  
public:
  vector<vector<int> > generateMatrix(int n) {
    
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int c=1;
    int k = 0;
    vector<vector<int> > ret;
    ret.resize(n);
    for (int i = 0; i<ret.size();i++)
      ret[i].resize(n);
    while (n>k*2) {
      
      for (int i = k; i<n-k; i++)
        ret[k][i] = c++;
      for (int i = k+1; i<n-k; i++)
        ret[i][n-k-1] = c++;
      if (n-k-1>k) {
        
        for (int i = n-k-2; i>=k; i--)
          ret[n-k-1][i] = c++;
        for (int i = n-k-2; i>k; i--)
          ret[i][k] = c++;
      }
      k++;
    }
    return ret;
        
  }
};
