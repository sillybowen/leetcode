class Solution {
  
  bool valid(string s) {
    
    stringstream ss;
    if (s.size()>3) return false;
    if (s.size()>1&&s[0]=='0') return false;
    int i;
    ss<<s;
    ss>>i;
    if (i<256) return true;
  }
  string valid (string s,int s1,int s2,int s3) {
    
    string ss;
    string ret="";
    string ss1,ss2,ss3,ss4;
    ss1 = s.substr(0,s1+1);
    ss2 = s.substr(s1+1,s2-s1);
    ss3 = s.substr(s2+1,s3-s2);
    ss4 = s.substr(s3+1,s.size()-s3-1);
    if (valid(ss1)&&valid(ss2) && valid(ss3) &&valid(ss4))
      return ss1+"."+ss2+"."+ss3+"."+ss4;
    return "";
  }
public:
  vector<string> restoreIpAddresses(string s) {
    
    vector<string> ret;
    if (s.size()>12) return ret;
    for (int s1 = 0; s1<s.size();s1++)
      for (int s2 = s1+1;s2<s.size();s2++)
        for (int s3 = s2+1; s3<s.size()-1;s3++) {
          
          string ss = valid(s,s1,s2,s3);
          if (ss!="")
            ret.push_back(ss);
        }
    return ret;
  }
};
