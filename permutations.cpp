class Solution {
  
  void dfs(int depth, 
           vector<int> &num, 
           vector<int> &tmp,
           vector<bool> &used, 
           vector<vector<int> > & ret) {
    
    if (depth == num.size()) {
      
      ret.push_back(tmp);
      return;
    }
    for (int i = 0; i<num.size(); i++) 
      if (!used[i]){
        
        used[i] = true;
        tmp[depth] = num[i];
        dfs(depth+1,num,tmp,used,ret);
        used[i] = false;
      }
  }
public:
  vector<vector<int> > permute(vector<int> &num) {
    
    vector<vector<int> > ret;
    vector<bool> used;
    vector<int> tmp;
    tmp.resize(num.size());
    used.resize(num.size(),false);
    dfs(0,num,tmp,used,ret);
    return ret;
  }
};
