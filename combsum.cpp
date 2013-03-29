class Solution {
  
  vector<vector<int> > ans;
  vector<int> can;
  void dfs(int start,int sum, int target,vector<int> tmp) {
    
    if (sum > target) return;
    if (sum == target) {
      ans.push_back(tmp);return;}
    if (start == can.size()) return;
        
    dfs(start+1,sum,target,tmp);
    vector<int> tmp2=tmp;
    int sum2 = sum;
    while( sum2<=target ) {
      
      sum2+=can[start];
      tmp2.push_back(can[start]);
      dfs(start+1,sum2,target,tmp2);
    }
  }
public:
  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    
    can = candidates;
    sort(can.begin(),can.end());
    ans.clear();
    vector<int> tmp;
    dfs(0,0,target,tmp);
    return ans;
  }
};
