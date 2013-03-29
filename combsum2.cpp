class Solution {
  vector<int> num_;
  vector<int> count;
  vector<vector<int> > ans;
  void dfs(int start,int sum, int target,vector<int> tmp) {
    if (sum>target) return;
    if (sum == target) {
      ans.push_back(tmp);return;}
    if (start>=num_.size()) return;

    dfs(start+1,sum,target,tmp);
    int sum2 = sum;
    vector<int> tmp2 = tmp;
    int c = 1;
    while (sum2<=target&& c<=count[start]) {

      sum2+=num_[start];
      c++;
      tmp2.push_back(num_[start]);
      dfs(start+1,sum2,target,tmp2);
    }
  }
public:
  vector<vector<int> > combinationSum2(vector<int> &num, int target) {

    vector<int> tmp = num;
    sort(tmp.begin(),tmp.end());
    num_.clear();
    count.clear();
    num_.push_back(tmp[0]);
    count.push_back(1);
    for (int i = 1; i< tmp.size();i++) {
      if (tmp[i] == tmp[i-1])
        count[count.size()-1] ++;
      else {

        count.push_back(1);
        num_.push_back(tmp[i]);
      }                    
    }
    tmp.clear();
    ans.clear();
    dfs(0,0,target,tmp);
    //ans.push_back(num_);
    //ans.push_back(count);
    return ans;            
  }
};
