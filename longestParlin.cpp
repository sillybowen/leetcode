class Solution {
  
public:
  string longestPalindrome(string s) {
    
    int retH=0,retLen=1;
    int head,tail;
    for (int i = 0; i<s.size()-1;i++) 
      for (int j = 0; j<=1;j++){
        
        head = i;
        tail = i+j;
        while (head>=0 && tail<s.size() && s[head] == s[tail]){
          
          head --;
          tail ++;
        }
        head++;
        tail--;
        if (tail-head+1>retLen) {
          
          retH = head;
          retLen = tail-head+1;
        }
            
      }
    return s.substr(retH,retLen);
  }
};
