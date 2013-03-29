class Solution {
  
public:
  vector<string> anagrams(vector<string> &strs) {
    
    vector< vector<string> >warehouse;
    map<vector<int>,int>  index;
    map<vector<int>,int> ::iterator it;
    vector<int> hh;
    vector<string> ret;
    hh.resize(26,0);
    for (int i = 0; i<strs.size();i++) {
      
      for (int j = 0; j<26; j++)
        hh[j] = 0;
      for (int j = 0; j<strs[i].size();j++){
        
        hh[strs[i][j]-'a']++;
      }
      it = index.find(hh);
      if (it == index.end()) {
        
        vector<string> s;
        s.push_back(strs[i]);
        warehouse.push_back(s);
        index.insert(pair<vector<int>,int> (hh,warehouse.size()-1));
      }
      else {
        
        warehouse[it->second].push_back(strs[i]);
      }            
    }
    for (int i = 0; i<warehouse.size();i++)
      if (warehouse[i].size() >1) {
        
        for (int j = 0; j<warehouse[i].size();j++)
          ret.push_back(warehouse[i][j]);
      }
    return   ret;
  }
};
