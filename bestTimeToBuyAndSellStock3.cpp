class Solution {
  
public:
  int maxProfit(vector<int> &prices) {
    
    if (prices.size()<=1) return 0;
        
    int ret = 0;
    vector<int> tillEnd;
    int ma = prices[prices.size()-1];
    tillEnd.resize(prices.size()+1);
    tillEnd[prices.size()] = 0;
    tillEnd[prices.size()-1] = 0;
    for (int i = prices.size()-2; i>=0; i--) {
      
      tillEnd[i] = tillEnd[i+1];
      if (ma-prices[i]>tillEnd[i])
        tillEnd[i] = ma- prices[i];
      if (prices[i]>ma)
        ma = prices[i];
    }
        
    int mi = prices[0];
    int tmp;
    for (int i = 1; i<prices.size();i++) {
      
      tmp = prices[i]-mi+tillEnd[i+1];
      if (tmp>ret)
        ret = tmp;
      if (mi>prices[i])
        mi = prices[i];
    }
    return ret;
  }
};
