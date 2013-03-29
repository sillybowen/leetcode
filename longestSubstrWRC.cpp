class Solution {
  
public:
    
  int lengthOfLongestSubstring(string s) {
    
    if (s.size() == 0) return 0;
    int ans = 1;
    vector<int> index;
    int head;
    index.resize(26,-1);
    for (int i = 0;i<s.size();i++) {
      
      if (index[s[i]-'a']>=head) {
        
        head = index[s[i]-'a']+1;
      }
      index[s[i]-'a'] = i;
      if (i-head+1>ans)
        ans = i-head+1;
    }
    return ans;
  }
};
