class Solution {
  
  int getIndex(char c) {
    
    if (c<'a' || c> 'z')
      return c-'A';
    else 
      return 26+ c-'a';
  }
public:
  string minWindow(string S, string T) {
    
    vector<int> count,count2;
    int ans = -1;
    int ansH,ansT;
    count.resize(52,-1);
    count2.resize(52,0);
    for (int i = 0; i<T.size();i++) {
      
      count[getIndex(T[i])]= 0;
      count2[getIndex(T[i])] ++;
    }
    int zeroCount = 0;
    for (int i = 0; i<52; i++) {
      
      if (count[i] == 0)
        zeroCount++;
    }
        
    int head = 0;
    for (int i = 0; i<S.size();i++) 
      if (count[getIndex(S[i])]!=-1){
        
        count[getIndex(S[i])] ++;
        if (count[getIndex(S[i])] == count2[getIndex(S[i])])
          zeroCount--;
        while (head<i) {
          
          if (count[getIndex(S[head])] == -1)
            head++;
          else if (count[getIndex(S[head])] > count2[getIndex(S[head])]) {
            
            count[getIndex(S[head])] --;
            head++;                         
          }
          else break;
        }
        if (zeroCount == 0 && (ans == -1 || i-head+1<ans)) {
          
          ans = i-head+1;
          ansH = head;
          ansT = i;
        }
      }
    if (ans == -1) return "";
    return S.substr(ansH,ans);
  }
};
