class Solution {
public:
  int numDecodings(string s) {
    if (s == "") return 0;
    vector<int> ans;
    ans.resize(s.size()+1,0);
    ans[0] = 1;
    for (int i = 0; i<s.size();i++) 
      if (ans[i] >0) {
        if (s[i] != '0') {
          ans[i+1]+=ans[i];
          if (i+1<s.size()) {
            int tmp = (s[i] -'0') * 10 + s[i+1] - '0';
            if (tmp<=26)
              ans[i+2] += ans[i];
          }
        }
      } 
    return  ans[s.size()];
  }
};
