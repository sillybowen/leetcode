class Solution {
  
  void dfs(vector<int> s, int index, vector<vector<int> > &ret, vector<int> &tmp){
    
    ret.push_back(tmp);
    tmp.resize(tmp.size()+1);
    for (int i = index; i<s.size(); i++) {
      
      tmp[tmp.size()-1] = s[i];
      dfs(s,i+1,ret,tmp);
    }
    tmp.resize(tmp.size()-1);
  }
public:
  vector<vector<int> > subsets(vector<int> &S) {
    
    sort(S.begin(),S.end());
    vector<vector<int> > ret;
    vector<int> tmp;
    dfs(S,0,ret,tmp);
    return ret;
  }
};
