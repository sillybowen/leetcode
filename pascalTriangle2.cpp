class Solution {
  
public:
  vector<int> getRow(int rowIndex) {
    
    // DO NOT write int main() function
    vector<int> l1;
    vector<int> l2;
    rowIndex++;
    if (rowIndex == 0) return l1;
    l1.push_back(1);
    for (int i = 2; i<=rowIndex; i++) {
      
      l2.clear();
      l2.push_back(1);
      for (int j = 1; j<=i-2; j++) {
        
        l2.push_back(l1[j-1]+l1[j]);
      }            
      l2.push_back(1);
      l1 = l2;
    }
    return l1;        
  }
};
