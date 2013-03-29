class Solution {
  
public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
     
    vector<int> ret;
    int k = 0;
    int m = matrix.size();
    if (m==0) return ret;
    int n = matrix[0].size();
    if (n==0) return ret;
        
    while (m>2*k&&n>2*k) {
      
      for (int i = k; i< n-k; i++)
        ret.push_back(matrix[k][i]);
      for (int i = k+1; i<m-k; i++)
        ret.push_back(matrix[i][n-k-1]);
      if (m-k-1>k)
        for (int i = n-k-2; i>=k; i--)
          ret.push_back(matrix[m-k-1][i]);
      if (n-k-1>k)
        for (int i = m-k-2; i>k;i--)
          ret.push_back(matrix[i][k]);
      k++;
    }
    return ret;
        
  }
};
