class Solution {
public:
  int largestRectangleArea(vector<int> &height) {
    if (height.size()==0) return 0;
    stack<int> h;
    stack<int> w;
    int ans = 0;

    for (int i = 0; i<height.size();i++){
      while (h.size()!=0 && h.top()>=height[i]) {
        int th,tw;
        th = h.top();
        tw = w.top();
        h.pop();
        w.pop();
        int lw;
        if (h.empty()) lw = -1;
        else lw = w.top();
        if (th == height[i]) tw++;
        if (th*(i-1-lw)>ans)
          ans = th*(i-1-lw);
      }
      h.push(height[i]);
      w.push(i);          
          
    }
    int lw = height.size();
    while (!h.empty()) {
      
      int th,tw;
      th = h.top();
      tw = w.top();
      h.pop();
      w.pop();
      int sw;
      if (h.empty()) sw = 0;
      else sw = w.top()+1;
      if (th*(lw-sw)>ans)
        ans = th*(lw-sw);
    }
    return ans;
  }
};
