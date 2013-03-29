class Solution {
  
    struct tt {
      
      char c;
      bool star;
    };
  vector<tt> getTT(const char *s) {
    
    vector<tt> ret;
    while (*s!='\0') {
      
      tt t;
      if (*s == '.') {
        
        t.c = '.';
        t.star = false;
        s++;
      }
      else if (*s == '*') {
        
        t.c = '*';
        t.star = true;
        s++;
      }
      else {
        
        t.c = *s;
        s++;
        t.star = false;
        if (*s == '*') {
          
          t.star = true;
          s++;
        }
      }
      ret.push_back(t);
    }
    return ret;
  }
public:
  bool isMatch(const char *s, const char *p) {
    
    vector<tt> ss = getTT(s);
    vector<tt> pp = getTT(p);        
    vector <vector<bool> > ans;
        
    ans.resize(ss.size()+1);
    for (int i = 0; i<ss.size(); i++)
      ans[i].resize(pp.size()+1,false);
        
    ans[0][0] = true;
    for (int i = 0; i<=ss.size(); i++) 
      for (int j = 0;j<=pp.size();j++) 
        if (ans[i][j]){
          
          if ( ss[i].star || pp[j].star) {
            
            if ((ss[i].c !='*' && pp[j].c!='*')
                ||(ss[i].c == '*' && pp[j].c== '*')) {
              
              if (ss[i].c == pp[j].c){
                
                if (i<ss.size())
                  ans[i+1][j] = true;
                if (j<pp.size()) 
                  ans[i][j+1] = true;
                if (i<ss.size() && j<pp.size())
                  ans[i+1][j+1] = true;
              }
            }
            else if (i<ss.size() && ss[i].c == '*'&&j<pp.size()) {
              char c = pp[j].c;
              int jj = j;
              while (jj<pp.size() && 
                     ((pp[jj].c ==c) ||
                      (pp[jj].c == '.') ||
                      (pp[jj].c == '*'))) {
                       ans[i+1][jj+1] = true;
                       jj++;
                     }
            }
            else if (j<pp.size()){
              char c = ss[j].c;
              int ii = i;
              while (ii<ss.size() && 
                     ((ss[ii].c ==c) ||
                      (ss[ii].c == '.') ||
                      (ss[ii].c == '*'))) {
                ans[ii+1][j+1] = true;
                ii++;
              }                            
            }
          }
          else {
            
            if (i<ss.size() && j<pp.size())
              if (ss[i] == pp[j] || ss[i] == '.' || pp[j] == '.')
                ans[i+1][j+1] = true;
          }
        }
    return ans[ss.size()+1][pp.size()+1];
  }
};
