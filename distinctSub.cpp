class Solution {
  
public:
  int numDistinct(string S, string T) {
    
    if (S=="" || T=="") return 0;
        
    vector<vector<int> > count;
    count.resize(S.size()+1);
    for (int i =0; i<=S.size();i++)
      count[i].resize(T.size()+1,0);
    count[0][0] = 1;
    for (int i = 0; i<S.size();i++)
      for (int j = 0; j<=T.size(); j++) 
        if (count[i][j]>0){
          
          count[i+1][j] += count[i][j];
          if (S[i] == T[j]) {
            
            count[i+1][j+1] += count[i][j];
          }                
        }
    return count[S.size()][T.size()];
  }
};
