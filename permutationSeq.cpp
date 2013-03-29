class Solution {
    int fact(int x) {
        int ret = 1;
        for (int i = 2; i<=x;i++)
            ret*=i;
        return ret;
    }
    string dfs(vector<bool> & s, int n,int k) {        
        if (n==0) return "";
        int index;
        int tmp = fact(n-1);
        
        if (n == 1)
          index = 0;
        else {
          index = (k-1)/tmp;
        }
        if (index == n) index --;
        int count = 0;
        for (int i = 0; i<s.size();i++) 
            if (s[i]){
                if (count == index) {
                    s[i] = false;
                    string ss;
                    char c;
                    c = i+1+'0';
                    ss.push_back(c);
                    return ss+dfs(s,n-1,(k-1)%tmp+1);                    
                }
                count ++;
            }
    }
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below                                                                                                                                 
        // DO NOT write int main() function                                                                                                                                       
        vector<bool> s;
        s.resize(n,true);
        return dfs(s,n,k);
    }
};