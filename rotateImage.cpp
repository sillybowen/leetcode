class Solution {
  
  void rotate(int i,int j, vector<vector<int> > &matrix) {
    
    int x[4];
    int y[4];
        
    x[0] = i;y[0] = j;
    x[1] = j; y[1] = matrix.size()-i-1;
    x[2] = matrix.size()-i-1; y[2] = matrix.size() - x[1] - 1;
    x[3] = y[2];  y[3] = i;
    int p1,p2;
    p1 = matrix[x[3]][y[3]];
    for (int i = 0 ; i<4; i++) {
      
      p2 = matrix[x[i]][y[i]];
      matrix[x[i]][y[i]] = p1;
      p1 = p2;
    }
  }
public:
  void rotate(vector<vector<int> > &matrix) {
    
    for (int i = 0; i< matrix.size()/2;i++) {
      
      for (int j = i; j<matrix.size() -i -1; j++)
        rotate(i,j,matrix);
    }
  }
};
