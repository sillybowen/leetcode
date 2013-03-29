class Solution {
  
public:
  int reverse(int x) {
    
    bool neg = false;
    int ret=0;
    if (x<0) {
      
      neg = true;
      x = -x;
    }
    while(x>0) {
      
      ret=ret*10 + x%10;
      x/=10;
    }
    if (neg) ret = -ret;
    return ret;
  }
};
