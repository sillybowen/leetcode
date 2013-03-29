class Solution {
  
public:
  int minDistance(string word1, string word2) {
    
    vector<vector<int> > dis;
    dis.resize(word1.size()+1);
    for (int i = 0; i<dis.size();i++)
      dis[i].resize(word2.size()+1,-1);
    dis[0][0] = 0;
    for (int i = 0; i<=word1.size();i++)
      for (int j = 0; j<=word2.size();j++) 
        if (dis[i][j]>=0){
          
          if (i<word1.size() && j<word2.size()) {
            
            
            if( word1[i] == word2[j]) {
              
              if (dis[i+1][j+1] == -1 || dis[i][j]<dis[i+1][j+1])
                dis[i+1][j+1] = dis[i][j];
            }
            else if (dis[i+1][j+1] == -1 || dis[i][j]+1<dis[i+1][j+1])
              dis[i+1][j+1] = dis[i][j]+1;                
          }
          if (i<word1.size())
            if (dis[i+1][j] == -1 || dis[i][j]+1<dis[i+1][j])
              dis[i+1][j] = dis[i][j]+1;
          if (j<word2.size())
            if (dis[i][j+1] == -1 || dis[i][j]+1<dis[i][j+1])
              dis[i][j+1] = dis[i][j]+1;
                        
        }
    return dis[word1.size()][word2.size()];
  }
};
