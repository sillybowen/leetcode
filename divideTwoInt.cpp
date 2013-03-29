#include<iostream>
using namespace std;
class Solution {
  
  long long abs(long long x) {
    
    if (x<0) return -x;
    return x;
  }
public:
  int divide(int dividend, int divisor) {
    
    bool neg = false;
    if (dividend<0) neg = !neg;
    if (divisor<0) neg = !neg;
    long long a = abs(dividend);
    long long b = abs(divisor);
    long long d = 0;
    while (b<<d<=a) {
      d++;
      cout<<"d:"<<d<<endl;
    }
    int ans=0;

    for (int i = d;i>=0;i--) {
      
      if (b<<i<=a) {
        ans = ans | 1<<i;
        a-= b<<i;
      }
      cout<<"ans:"<<ans<<endl;
      cout<<"a:"<<endl;
    }
    if (neg) ans = -ans;
    return ans;
        
  }
};

int main() {
  Solution s;
  s.divide(6,2);
}
