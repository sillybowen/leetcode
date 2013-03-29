class Solution {
  
public:
  int sqrt(int x) {
    
    unsigned long long lar = x;
    unsigned long long start = 1;
    unsigned long long end = 2;
    while (end*end<=lar) 
      end*=2;
    unsigned long long tmp;    
    while (end-start>5){
      
      int mid = (end+start)/2;
      tmp = (unsigned long long)(mid*mid);
      if (tmp>lar)
        end = mid;
      else 
        start = mid;
    }
    int ans;
    for (unsigned long long i = start; i<=end; i++)
      if (i*i>lar) {
        
        ans = i-1;
        return ans;
      }
  }
};
