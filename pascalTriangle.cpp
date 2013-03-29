class Solution {
  
public:
  vector<vector<int> > generate(int numRows) {
    
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<int> l1;
    vector<vector<int> > ret;
    if (numRows == 0) return ret;
    l1.push_back(1);
    ret.push_back(l1);
    for (int i = 2; i<=numRows; i++) {
      
      l1.clear();
      l1.push_back(1);
      for (int j = 1; j<=i-2; j++) {
        
        l1.push_back(ret[i-2][j-1]+ret[i-2][j]);
      }            
      l1.push_back(1);
      ret.push_back(l1); 
    }
    return ret;
         
  }
};
