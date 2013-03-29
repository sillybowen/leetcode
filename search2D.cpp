#include <vector>
#include <iostream>
using namespace std;
class Solution {
  
  int locateLine(vector<vector<int> > & matrix, int target) {
    
    int start = 0;
    int end = matrix.size() -1;
    int ret = -1;
    if (end == 0) return 0;
    while (start<=end && start<matrix.size() && end>=0 ) {
      int mid = (end+start)/2;
      if ( matrix[mid][0]>target) {
        
        end = mid -1;
      }
      else if (matrix[mid][matrix[mid].size()-1]<target) {
        
        start = mid + 1;
      }
      else {
                    
        ret = mid;
        break;
      }
    }
    return ret;
  }
  int locateRow(vector<int> line,int target) {
    
    int ret = -1;
    int start = 0;
    int end = line.size() -1;
        
    while (start<=end) {
      
      int mid = (start+end) /2;
      if (line[mid]>target) end = mid -1;
      else if (line[mid]<target) start = mid +1;
      else {
        
        ret = mid;
        break;
      }
    }
    return ret;
  }
public:
  bool searchMatrix(vector<vector<int> > &matrix, int target) {
    
    int l = locateLine( matrix,target);
    cout<<l<<endl;
    if (l == -1) return false;
    int r = locateRow(matrix[l],target);
    cout<<r<<endl;
    if (r == -1) return false;
    return true;
  }
};

int main() {
  vector<vector<int> > matrix;
  matrix.resize(2);
  matrix[0].push_back(1);
  matrix[1].push_back(3);
  Solution s;
  s.searchMatrix(matrix,3);
}
