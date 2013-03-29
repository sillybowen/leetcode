class Solution {
  
  int bs(int A[], int n, int target, int mode) {
    
    int start = 0;
    int end = n-1;
    int ret=-1;
        
    while (start<end) {
      
      int mid = (start+end)/2;
      if (A[mid]>target) {
        
        end = mid -1;        
      } else if (A[mid]<target) {
        
        start = mid +1;
      } else {
        
        if (mode == 1){
          
          if (mid-1>=0 && A[mid-1] == target)
            end = mid -1;
          else return mid;
        } else {
          
          if (mid+1<n && A[mid+1] == target) 
            start = mid+1;
          else return mid;                    
        }
      }
    }
    if (ret == -1)
      if (A[start] == target) 
        ret = start;
    return ret;
  }
public:
  vector<int> searchRange(int A[], int n, int target) {
    
    vector<int> ret;
    ret.resize(2);
    ret[0] = bs(A,n,target,1);
    ret[1] = bs(A,n,target,2);
    return ret;
  }
};
