class Solution {

public:
  int maximalRectangle(vector<vector<char> > &matrix) {

    vector<vector<int> >max;
    max.resize(matrix.size());
    int ans = 0;
    for (int i = 0; i<max.size();i++)
      max[i].resize(matrix[i].size());
    for (int i = 0; i<max.size();i++) {
      for (int j = 0; j<max[i].size();j++) {

        if (matrix[i][j] == '0')
          max[i][j] = 0;
        else if (j == 0)
          max[i][j] = 1;
        else max[i][j] = max[i][j-1]+1;

        int min = max[i][j];
        for (int j1 = i; j1>=0;j1--){

          if (max[j1][j]<min)
            min = max[j1][j];
          if (min*(i-j1+1)>ans)
            ans = min*(i-j1+1);
        }
      }

    }
    return ans;
  }
};
