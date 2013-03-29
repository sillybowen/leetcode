class Solution {
  
public:
  int longestValidParentheses(string s) {
    
    int ans=0;
    stack<int> st;
    int head = -1;
    for (int i = 0; i<s.size();i++) {
      
      if (s[i] == '(')
        st.push(i);
      else if (!st.empty()) {
        
        st.pop();
        if (st.empty()) {
          
          if (i-head>ans)
            ans = i-head;
        }
        else {
          
          if (i-st.top()>ans)
            ans = i-st.top();
        }                    
      }
      else {
        
        head = i;
      }
    }
    return ans;
  }
};
