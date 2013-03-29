class Solution {
  
  int ans;
  vector<bool> ver;
  vector<bool> ldiag,rdiag;
  vector<int> hor;
    
  void dfs(int dep,int n) {
    
    if (dep == n) {
      
      ans ++;
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
  int totalNQueens(int n) {
    
    ver.clear();
    rdiag.clear();
    ldiag.clear();
    ans = 0;
        
    hor.resize(n);
    ver.resize(n,false);
    rdiag.resize(n+n-1,false);
    ldiag.resize(n+n-1,false);

    dfs(0,n);
    return ans;
  }
};
