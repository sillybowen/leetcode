class Solution {
  int abs(int x) {
    if (x<0)
      return -x;
    return x;
  }
public:
  int threeSumClosest(vector<int> &num, int target) {
    int ret = num[0]+num[1]+num[2];
    vector<int>num2 = num;
    sort(num2.begin(),num2.end());
    int head,tail;
    for (int i = 0; i< num2.size(); i++) {
      head = i+1;
      tail = num2.size()-1;
      int sum;
      while(head<tail){
        sum = num2[i]+num2[head];
        while (sum+num2[tail-1]>target&&tail-1>head)
          tail --;
        if (tail>head) {
          if (abs(ret-target)>abs(sum+num2[tail]-target))
            ret = sum+num2[tail];
        }
        if (tail-1>head) {
          if (abs(ret-target)>abs(sum+num2[tail-1]-target))
            ret = sum+num2[tail-1];
        }
        head++;
      }
    }
    return ret;
  }
};
