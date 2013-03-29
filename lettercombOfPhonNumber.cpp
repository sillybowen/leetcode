class Solution {
  
  void dfs(string digits, int len, string map[], 
           vector<string> &ret,string&now) {
    
    if (len == digits.size()) {
      
      ret.push_back(now);
      return ;
    }
    int index = digits[len]- '0';
    for (int i = 0; i<map[index].size();i++) {
      
      now[len] = map[index][i];
      dfs(digits,len+1,map,ret,now);
    }
  }
public:
  vector<string> letterCombinations(string digits) {
            
    vector<string> ret;
        string map[] = {
          " "," ","abc","def","ghi",
          "jkl","mno","pqrs","tuv","wxyz"};
        string now;
        now.resize(digits.size());
        dfs(digits,0,map,ret,now);
        return ret;
  }
};
