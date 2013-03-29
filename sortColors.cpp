class Solution {
  
  void swap(int &a ,int &b) {
    
    int tmp = a;
    a = b;
    b = tmp;
  }
  int min (int a,int b) {
    
    if (a<b) return a;
    return b;
  }
  int max(int a,int b){
    
    if (a>b) return a;
    return b;
  }
public:
  void sortColors(int A[], int n) {
    
    int b = -1;
    int a = 0;
    while (a<n && b<n) {
      
      while (a<n && A[a] == 0) a++;
      if (a<n) {
        
        b = max(a+1,b);
        while (b<n && A[b]!=0) b++;
        if (b<n) {
          
          swap(A[a],A[b]);
          a++;
          b++;
        }
      }
    }
    a = n-1;
    b = n;
    while (a>=0 && b>=0) {
      
      while (a>=0 && A[a] == 2) a--;
      if (a>=0) {
        
        b = min(a-1,b);
        while (b>=0 && A[b]!=2) b--;
        if (b>=0) {
          
          swap(A[a],A[b]);
          a--;
          b--;
        }
      }
    }
  }
};
