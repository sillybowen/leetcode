class Solution {
  
public:
  void setZeroes(vector<vector<int> > &matrix) {
    
    int l = -1;
    int r = -1;
    for (int i = 0; i<matrix.size(); i++)
      for (int j = 0; j<matrix[i].size(); j++) 
        if (matrix[i][j] == 0){
          
          if (l!=-1) {
            
            matrix[l][j] = 0;
            matrix[i][r] = 0;
          }
          else {
            
            l = i;
            r = j;
          }
        }
    if (l == -1) return;
    for (int i = 0; i<matrix.size(); i++) {
      
      if (matrix[i][r] == 0 && i!=l)
        for (int j = 0; j< matrix[i].size(); j++)
          matrix[i][j] = 0;
    }
    for (int j = 0; j< matrix[l].size(); j++) {
      
      if (matrix[l][j] == 0)
        for (int i = 0; i<matrix.size(); i++)
          matrix[i][j] = 0;
    } 
    for (int i = 0; i<matrix.size();i++)
      matrix[i][r] = 0;
    for (int j = 0; j<matrix[l].size();j++)
      matrix[l][j] = 0;
  }
};
