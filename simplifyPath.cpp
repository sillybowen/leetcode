#include <string>
#include <stack>
#include <iostream>
using namespace std;
class Solution {
  
public:
  string simplifyPath(string path) {
    
    stack<string> dirs;
    int i  = 0;
    while (i<path.size()) {
      
      while (i<path.size() && path[i]=='/') i++;
      if (i==path.size()) break;
      if (path[i] == '.') {
                        
        if (i+1<path.size()&&path[i+1] == '.') {
          
          if (!dirs.empty())
            dirs.pop();
          i++;
        }
        i++;
      }
      else {
        
        int j = i;
        while (j+1<path.size() && path[j+1]!='/')
          j++;
        dirs.push(path.substr(i,j-i+1));
        cout<<dirs.top()<<endl;
        i = j+1;
      }
    }
    string ret="";
    while (!dirs.empty()) {
      string tmp = dirs.top();
      dirs.pop();
      ret= "/"+tmp+ret;
      cout<<tmp<<endl;
      cout<<ret<<endl;
    }
    if (ret=="") ret = "/";
    return ret;
  }
};

int main() {
  string s = "/home/foo";
  Solution so;
  cout<<so.simplifyPath(s)<<endl;
}
