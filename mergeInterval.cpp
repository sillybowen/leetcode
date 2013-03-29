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
bool compare(Interval v1,Interval v2) {
  
  return v1.start<v2.start;
}
class Solution {
  
  bool overlap(Interval v1,Interval v2) {
    
    return ((v1.start>=v2.start && v1.start<=v2.end) ||
            (v2.start>=v1.start&& v2.start<=v1.end));
  }
  Interval merge (Interval v1,Interval v2) {
    
    Interval v;
    v.start = v1.start<v2.start? v1.start: v2.start;
    v.end = v1.end>v2.end? v1.end: v2.end;
    return v;
  }
public:
  vector<Interval> merge(vector<Interval> &intervals) {
    
    vector<Interval> ret;
    if (intervals.size()==0) return ret;
    vector<Interval> s = intervals;
    sort(s.begin(),s.end(),compare);
        
    Interval tmp = s[0];
    for (int i = 1; i<s.size();i++) {
      
      if (overlap(tmp,s[i])) {
        
        tmp = merge(tmp,s[i]);
      }
      else {
        
        ret.push_back(tmp);
        tmp = s[i];
      }
    }
    ret.push_back(tmp);
    return ret;
  }
};
