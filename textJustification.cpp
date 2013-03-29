class Solution {
  
public:
  vector<string> fullJustify(vector<string> &words, int L) {
    
    int head,tail;
    head = 0;
    vector<string> ret;
    if (words.size()==0) 
      return ret;

    while (head<words.size()) {
      
      tail = head;
      int l = words[head].size()+1;
      while (tail+1<words.size() && l+words[tail+1].size()<=L) {
        
        tail ++;
        l=l+words[tail].size()+1;
      }
      string s="";
      l = L;
      for (int i = head; i<=tail;i++)
        l-= words[i].size();
      int sc;
      for (int i = head; i<=tail; i++) {
        
        s+=words[i];
        if (tail == words.size()-1) {
          
          if (i == tail) sc = l;
          else sc = 1;
        }
        else {
          
          if (tail == i) sc = l;
          else {
            
            sc = l/(tail-i);
            if (tail-i) >0) sc++;
        }
      }
      s.resize(s.size()+sc,' ');
      l-=sc;
    }
    ret.push_back(s);
    head = tail+1;
  }
}
  };
