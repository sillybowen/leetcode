class Solution {
public:
    double pow(double x, int n) {
        double ans;
        bool neg = false;
        int tmp = n;
        if (n<0) {
            neg = true;
            tmp = -tmp;
        }
        
        if (n == 0) return 1;
        
        ans = pow(x,tmp/2);
        ans = ans * ans;
        
        if (tmp%2==1) ans*= x;
        if (neg) return 1.0/ans;
        return ans;
    }
};