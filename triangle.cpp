class Solution {
  
  int min(int a,int b){
    
    return a<b? a: b;
  }
public:
  int minimumTotal(vector<vector<int> > &triangle) {
    
    if (triangle.size()==0) return 0;
    if (triangle.size() ==1) return triangle[0][0];
    vector<int> ret;
    vector<int> last;
    ret.resize(1,0);
    ret[0] = triangle[0][0];
        
    for (int i = 1; i<triangle.size();i++) {
      
      last = ret;
      ret.clear();
      ret.resize(i+1);
      ret[0] = last[0]+triangle[i][0];
      ret[i] = last[i-1]+triangle[i][i];
      for (int j = 1; j<i;j++)
        ret[j] = min(last[j-1]+ triangle[i][j],
                     last[j]+triangle[i][j]);
    }
    int ans = ret[0];
    for (int i = 0; i<ret.size();i++)
      if (ret[i]<ans) ans = ret[i];
    return ans;
  }
};
