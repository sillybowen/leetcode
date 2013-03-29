#include<iostream>
#include<vector>
using namespace std;
class Solution {
  vector<vector<bool> > line,row,rec;
  vector<int> getAllPossibleValue(int x,int y) {
    vector<int> ret;
    for (int p = 0; p<9; p++) {
      if (row[y][p] && line[x][p] && rec[x/3*3+y/3][p]) {
        ret.push_back(p);
//        cout<<"line:"<<x<<' '<<y<<' '<<"could be"<< p+1<<endl;
      }
    }
    return ret;
  }
  bool getLineRowRec(vector <vector<char> > &board) {
    line.clear();
    row.clear();
    rec.clear();
    line.resize(9);
    row.resize(9);
    rec.resize(9);
    for (int i = 0; i<9; i++) {
      line[i].resize(9,true);
      row[i].resize(9,true);
      rec[i].resize(9,true);
    }
    for (int i = 0; i<board.size(); i++)
      for(int j = 0; j<board[i].size(); j++) 
        if (board[i][j]!='.'){
          int n = board[i][j] - '1';
          if (!line[i][n]) return false;
          else line[i][n] = false;
          if (!row[j][n]) return false;
          else row[j][n] = false;
          if (!rec[i/3*3 +j/3][n]) return false;
          else rec[i/3*3+j/3][n] = false;
        }
  }
  bool checkValid(vector<vector<char> >&board) {
    for (int i = 0; i<9;i++)
      for (int j = 0; j<9; j++)
        if (board[i][j]=='.') {
          if (getAllPossibleValue(i,j).size()==0)
            return false;
        }
    return true;
  }
  bool dfs(vector<vector<char> > &board,int xx,int yy) {
    if (!checkValid(board)) return false;
    int x = xx;
    int y = yy;
//    cout<<"dfs"<<x<<' '<<y<<endl;
//    output(board);
//    cout<<endl;
    while (x<9) {
      if (board[x][y] != '.') {
        y++;
        if (y == 9) {
          x++;
          y = 0;
        }
      }
      else break;
    }
    if (x == 9) return true;
    vector<int> po = getAllPossibleValue(x,y);
    for (int i = 0; i<po.size();i++) {
//      cout<<x<<' '<<y<<' '<<po[i]<<endl;
      board[x][y] = '1' + po[i];
      row[y][po[i]] = false;
      line[x][po[i]] = false;
      rec[x/3*3+y/3][po[i]] = false;
      bool r;
      if (y==8) r =dfs(board,x+1,0);
      else r =dfs(board,x,y+1);
      if (r) return true;
      board[x][y] = '.';
      row[y][po[i]] = true;
      line[x][po[i]] = true;
      rec[x/3*3+y/3][po[i]] = true;
    }
    return false;
  }
public:
  void output(vector<vector<char> > bb) {
    for (int i = 0; i<bb.size();i++)
      {
        for (int j = 0; j<bb[i].size();j++)
          cout<<bb[i][j];
        cout<<endl;
      }
    cout<<endl;
  }

  void solveSudoku(vector<vector<char> > &board) {
    if (!getLineRowRec(board))
      return ;
    bool r = dfs(board,0,0);
    output(board);
  }
};

int main () {
   string bb[9] = 
     {
       "53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};
//     {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
  vector<vector<char> >bo;
  bo.resize(9);
  for (int i = 0; i<9;i++) {
    bo[i].resize(9);
    for (int j = 0; j<9;j++){
      bo[i][j] = bb[i][j];
    }
  }
  Solution s;
  s.solveSudoku(bo);
  s.output(bo);
}
