class Solution {
  vector<vector<int> > ans;
  vector<int> tmp;
  void dfs(int start,int used,int n,int k) {
    if (used == k) {
      ans.push_back(tmp); return;}
    if (start>n) return;
    dfs(start+1,used,n,k);
    tmp[used] = start;
    dfs(start+1,used+1,n,k);
  }
public:
  vector<vector<int> > combine(int n, int k) {
    ans.clear();
    tmp.resize(k);
    dfs(1,0,n,k);
    return ans;
  }
};
