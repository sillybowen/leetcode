class Solution {
  
  string get(string s) {
    
    string ret;
    int index = 0;
    int count ;
    while (index<s.size()) {
      
      count = 1;
      while (count+index<s.size() && s[count+index] == s[index]) {
        
        count++;
      }
      ret.push_back('0'+count);
      ret.push_back(s[index]);
      index = index+count;
    }
    return ret;
  }
public:
  string countAndSay(int n) {
    
    string s = "1";
    string ans = s;
    for (int i = 2; i<=n; i++) {
      
      ans = get(s);
      s = ans;
    }
    return ans;
  }
};
