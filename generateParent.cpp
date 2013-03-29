class Solution {
  
  vector<string> ans;
  void dfs(int left,int right,int n, string s) {
    
    if (left ==n && right == n) {
      
      ans.push_back(s);
      return;
    }
    if (left<n) {
      
      dfs(left+1,right,n,s+"(");
    }
    if (right<left) {
      
      dfs(left,right+1,n,s+")");
    }
  }
public:
  vector<string> generateParenthesis(int n) {
    
    ans.clear();
    dfs(0,0,n,"");
    return ans;
  }
};
