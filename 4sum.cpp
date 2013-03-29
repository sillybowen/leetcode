class Solution {
  
public:
  vector<vector<int> > fourSum(vector<int> &num, int target) {
    
    vector<int> num2 = num;
    vector<int> tmp;
    vector<vector<int> > ret;
    set<vector<int> > lookup;
    tmp.resize(4);
    sort(num2.begin(),num2.end());
    int head,tail,sum;
    for (int i = 0; i<num2.size();i++) 
      for(int j = i+1;j<num2.size();j++) {
        
        tmp[0] = num2[i];
        tmp[1] = num2[j];
        head = j+1;
        tail = num2.size()-1;
        while (tail>head) {
          
          tmp[2] = num2[head];
          sum = -(tmp[0]+tmp[1]+tmp[2]-target);
          while (num2[tail]>sum && tail>head) {
            
            tail--;
          }
          if (num2[tail] == sum && tail>head) {
            
            tmp[3] = num2[tail];
            if (lookup.find(tmp) == lookup.end()) {
              
              lookup.insert(tmp);
              ret.push_back(tmp);
            }
          }
          head++;
        }
      }   
    return ret;
  }
};
