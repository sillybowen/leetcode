class Solution {
  void swap(int & a, int & b) {
    int tmp = a;
    a = b;
    b = tmp;
  }
public:
  void nextPermutation(vector<int> &num) {

    if (num.size()<2) return;
    int tail = num.size()-2;
    while (tail>=0 && num[tail]>=num[tail+1])
      tail --;
    if (tail == -1) {
      // reverse
      for (int i = 0; i<num.size()/2; i++) {
        swap(num[i],num[num.size()-1-i]);
      }
      return;
    }
    int index = tail + 1;
    for (int j = tail + 1; j<num.size(); j++) {
      if (num[tail]<num[j] && num[j]<num[index]) 
        index = j;
    }
    swap(num[tail],num[index]);
    sort(num.begin()+tail+1,num.end());
  }
};
