/**
 * Definition for an interval.
 * struct Interval {
 
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {
 }
 *     Interval(int s, int e) : start(s), end(e) {
 }
 * };
 */
class Solution {
  
  bool overlap(Interval i1, Interval i2) {
    
    if ((i1.start<=i2.end && i1.start >=i2.start)||
        (i1.end<=i2.end && i1.end >=i2.start))
      return true;
    if ((i2.start<=i1.end && i2.start >= i1.end) ||
        (i2.end<=i1.end && i2.end >=i1.start) )
      return true;
    return false;    
  }
  void merge(Interval & i1, Interval i2) {
    
    if (i2.start<i1.start)
      i1.start = i2.start;
    if (i2.end>i1.end)
      i1.end=i2.end;
  }
public:
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    
    vector<Interval> ret;
    Interval tmp = newInterval;
    int stat=0;
    for (int i = 0; i<intervals.size();i++) {
      
      if (overlap(intervals[i],tmp)) {
        
        merge(tmp,intervals[i]);
        stat = 1;
      }
      else {
        
        if (stat<2 && intervals[i].start>tmp.end) {
          
          stat = 2;
          ret.push_back(tmp);
        }
        ret.push_back(intervals[i]);                
      }
    }
    if (stat <2)
      ret.push_back(tmp);
    return ret;
  }
};
