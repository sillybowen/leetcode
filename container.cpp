class Solution {
  
public:
  int maxArea(vector<int> &height) {
    
    int ans = 0;
    int head = 0;
    int tail = height.size()-1;
    while(tail>head) {
      
      if (height[tail]>height[head]) {
        
        if (height[head]*(tail-head)>ans)
          ans = height[head]*(tail-head);
        int x = head;
        while (height[x]<=height[head] && x<tail)
          x++;
        head = x;
      }   
      else {
        
        if (height[tail]*(tail-head)>ans)
          ans = height[tail]*(tail-head);
        int x = tail;
        while (height[x]<=height[tail] && x>head)
          x --;
        tail = x;
                
      }
    }
    return ans;
  }
};
