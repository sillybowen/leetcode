class Solution {
  
public:
  int minPathSum(vector<vector<int> > &grid) {
    
    vector<vector<int> > ans;
    ans.resize(grid.size());
    for (int i = 0; i<ans.size(); i++)
      ans[i].resize(grid[i].size(),-1);
    ans[0][0] = grid[0][0];
    for (int i = 0; i<ans.size();i++)
      for (int j = 0; j<ans[i].size();j ++) {
        
        if (i+1<ans.size()) {
          
          if (ans[i][j] + grid[i+1][j]<ans[i+1][j] || ans[i+1][j] == -1)
            ans[i+1][j] = ans[i][j] + grid[i+1][j];
        }
        if (j+1<ans[i].size()) {
          
          if (ans[i][j] + grid[i][j+1]<ans[i][j+1] || ans[i][j+1] == -1)
            ans[i][j+1] = ans[i][j] + grid[i][j+1];
        }
      }
    return ans[ans.size()-1][ans[0].size()-1];
  }
};
