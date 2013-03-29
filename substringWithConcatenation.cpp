class Solution {
  
  void buildDic(map<string,int> &dic, vector<string> &L) {
    
    for (int i = 0; i<L.size();i++)
      dic.insert(pair<string,int> (L[i],i));
        
  }
  void buildMatch(vector<int>& match,string S, vector<string> &L,
                  map<string,int> &dic) {
    
    int len = L[0].size();
    map<string,int>::iterator it;
    match.resize(S.size(),-1);
    for (int i = 0; i+len-1<S.size(); i++) {
      
      it = dic.find(S.substr(i,len));
      if (it!=dic.end())
        match[i] = it->second;
      else
        match[i] = -1;
    }
  }
public:
  vector<int> findSubstring(string S, vector<string> &L) {
    
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    map<string,int> dic;
    buildDic(dic,L);
        
    vector<int> match;
    int len = L[0].size();
    buildMatch(match,S,L,dic);
        
    vector<int> ret;
    set<int> matched;
    for (int i = 0; i<len; i++) {
      
      int head = -1;
      int tail = i;
      while (tail<S.size()) {
        
        if (match[tail]!=-1) {
          
          if (head == -1) {
            
            head = tail;
            matched.insert(match[tail]);
          } else {
            
            if (matched.find(match[tail])!=matched.end()) {
              
              while(match[head]!=match[tail]) {
                
                matched.erase(match[head]);
                head+=len;
              }
              matched.erase(match[head]);
              head+=len;
            }
            matched.insert(match[tail]);
          }
          if (matched.size()==L.size())
            ret.push_back(head);                            
                            
        } else {
              
          head = -1;
          matched.clear();
        }
        tail = tail+len;
      }
    }        
    return ret;            
  }
};
