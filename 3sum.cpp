#include<algorithm>
#include<set>
class Solution {

public:
  vector<vector<int> > threeSum(vector<int> &num) {
    vector<int> tmp;
    vector<vector<int> > ret;
    set<vector<int> > lookup;
    vector<int> nums;
    tmp.resize(3);
    nums = num;
    sort(nums.begin(),nums.end());
    int head,tail,sum;
    for (int i = 0; i<nums.size(); i++) {
      head = i+1;
      tail = nums.size()-1;
      tmp[0] = nums[i];
      while (head<tail) {
        tmp[1] = nums[head];
        sum = -(tmp[0] + tmp[1]);
        while( nums[tail]>sum && tail>head) {
          tail--;
        }
        if (nums[tail] == sum && tail>head) {
          tmp[2] = nums[tail];
          if (lookup.find(tmp) == lookup.end()) {
            lookup.insert(tmp);
            ret.push_back(tmp);
            tail--;
          }
        }
        head++;
      }
    }
    return ret;
  }
};
