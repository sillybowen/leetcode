class Solution {
  
  bool dfs(int i,int j, string word,vector<vector<char> >&board, int index) {
    
    if (word.size() == index) return true;
    if (i<0 || j<0 || i>=board.size()|| j>=board[0].size()) return false;
    if (board[i][j] != word[index]) 
      return false;
    char c = board[i][j];    
    board[i][j] = '.';
    if (dfs(i+1,j,word,board,index+1) ||
        dfs(i,j+1,word,board,index+1) ||
        dfs(i-1,j,word,board,index+1) ||
        dfs(i,j-1,word,board,index+1))
      return true;
            
    board[i][j] = c;
    return false;
  }
public:
  bool exist(vector<vector<char> > &board, string word) {
    
    if (word.size() == 0) return true;
    if (board.size() == 0) return false;
    if (board[0].size()==0) return false;
        
    for (int i = 0; i<board.size(); i++)
      for (int j = 0; j<board[i].size();j++) {
        
                bool r = 
                  dfs(i,j,word,board,0);
                if (r) return true;
      }
    return false;
  }
};
