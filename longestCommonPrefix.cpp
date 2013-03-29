class Solution {
  
public:
  string longestCommonPrefix(vector<string> &strs) {
    
    if (strs.size()==0) return "";
        
    string tmp = strs[0];
    int len;
    int commonLen;
    for (int i = 1; i<strs.size(); i++) {
      
      len = tmp.size()<strs[i].size()?tmp.size():strs[i].size();
      commonLen = 0;
      while (commonLen<len) {
        
        if (tmp[commonLen] == strs[i][commonLen])
          commonLen++;
        else
          break;
      }
      if (commonLen == 0) return "";
      if (commonLen<tmp.size())
        tmp = tmp.substr(0,commonLen);
    }
    return tmp;
  }
};
