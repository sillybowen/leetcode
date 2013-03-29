class Solution {
  
public:
  bool isPalindrome(int x) {
    
    if (x<0) return false;
    stringstream ss;
    string s;
    ss<<x;
    ss>>s;
    for (int i = 0; i<s.size()/2;i++) {
      
      if (s[i] != s[s.size()-1-i])
        return false;
    }
    return true;
  }
};
