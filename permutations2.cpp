class Solution {
  
  void dfs(int depth,
           int tot,
           vector<int> &num, 
           vector<int> &tmp,
           vector<int> &count, 
           vector<vector<int> > & ret) {
    
    if (depth == tot) {
      
      ret.push_back(tmp);
      return;
    }
    for (int i = 0; i<num.size(); i++) 
      if (count[i]>0){
        
        count[i] -= 1;
        tmp[depth] = num[i];
        dfs(depth+1,tot,num,tmp,count,ret);
        count[i]+=1;
      }
  }
public:
  vector<vector<int> > permuteUnique(vector<int> &num) {
    
    vector<vector<int> > ret;
    vector<int> num1;
    vector<int> count;
    vector<int> tmp;
    for (int i = 0; i<num.size(); i++) {
      
      bool r = false;
      for (int j = 0; j<num1.size(); j++)
        if (num1[j] == num[i]) {
          
          r = true;
          count[j] ++;
        }
                
      if (!r) {
        
        num1.push_back(num[i]);
        count.push_back(1);
      }
    }
    tmp.resize(num.size());
    dfs(0,num.size(),num1,tmp,count,ret);
    return ret;
  }
};
