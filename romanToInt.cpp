class Solution {
  
public:
  int romanToInt(string s) {
    
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int ret=0;
    map<char,int> dic;
    dic.insert(pair<char,int> ('I',1));
    dic.insert(pair<char,int> ('V',5));
    dic.insert(pair<char,int> ('X',10));
    dic.insert(pair<char,int> ('L',50));
    dic.insert(pair<char,int> ('C',100));
    dic.insert(pair<char,int> ('D',500));
    dic.insert(pair<char,int> ('M',1000));
    int last=-1;
    int now;
    for (int i = 0; i<s.size(); i++) {
      
      now = dic.find(s[i])->second;
      ret+=now;
      if (last != -1 && last<now) {
        
        ret=ret-2*last;
      }
      last = now;            
    }
    return ret;

  }
};
