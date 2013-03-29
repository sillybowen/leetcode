class Solution {
  
public:
  int lengthOfLastWord(const char *s) {
    
    int now = 0;
    int last = 0;
    const char *tmp = s;
    int i = 0;
    while (s[i]!='\0') {
      
      if (s[i]==' '&&now>0) {
        
        last = now;
        now = 0;
      }
      else if (s[i]!=' ')
        now ++;
      i++;                
    }
    if (now == 0) return last;
    return now;
  }
};
