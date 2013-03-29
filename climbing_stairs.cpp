class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        vector<int> ans;
        ans.resize(3,0);
        ans[0] = 1;
        ans[1] = 1;
        
        for (int i = 2; i<=n; i++)
            ans[i%3] = ans[(i-2)%3]+ans[(i-1)%3];
            
        return ans[n%3];
    }
};