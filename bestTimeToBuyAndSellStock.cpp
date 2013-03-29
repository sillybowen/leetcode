class Solution {
  
public:
  int maxProfit(vector<int> &prices) {
    
    if (prices.size() == 0) return 0;
    int ret = 0;
    int mi = prices[0];
    for (int i = 1; i<prices.size();i++) {
      
      if (prices[i]-mi>ret)
        ret = prices[i]-mi;
      if (prices[i]<mi)
        mi=prices[i];
    }
    return ret;
  }
};
