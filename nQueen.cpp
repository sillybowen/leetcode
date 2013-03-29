class Solution {
  
  vector<vector<string> > ret;
  vector<bool> ver;
  vector<bool> ldiag,rdiag;
  vector<int> hor;
    
  void getSol (int n) {
    
    vector<string> tmp;
    tmp.resize(n);
    string s;
    s.resize(n);
    for (int i = 0; i<n; i++) {
      
      for (int j = 0; j<n; j++)
        if (hor[i] == j)
          s[j] = 'Q';
        else 
          s[j] = '.';
      tmp[i] = s;
    }
    ret.push_back(tmp);
  }
  void dfs(int dep,int n) {
    
    if (dep == n) {
      
      getSol(n);
      return;
    }
        
    for (int i = 0; i<n; i++) {
      
      if (ver[i] == false && !rdiag[n-1+dep-i] && !ldiag[dep+i]) {
        
        hor[dep] = i;
        ver[i] = true;
        rdiag[n-1+dep-i] = true;
        ldiag[dep+i] = true;
        dfs(dep+1,n);
        ldiag[dep+i] = false;
        rdiag[n-1+dep-i] = false;
        ver[i] = false;
      }            
    }
  }
public:
  vector<vector<string> > solveNQueens(int n) {
    
    ret.clear();
    ver.clear();
    rdiag.clear();
    ldiag.clear();
        
    hor.resize(n);
    ver.resize(n,false);
    rdiag.resize(n+n-1,false);
    ldiag.resize(n+n-1,false);

    dfs(0,n);
    return ret;
  }
};
