#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution {
  vector<int> getNext(char* s) {
    vector<int> next;
    int i = 0;
    int j = -1;
    next.push_back(-1);
    while (s[i]!='\0') {
      while (j>=0 && s[i]!=s[j])
        j = next[j];
      i++;
      j++;
      next.push_back(j);
    }
    return next;
  }
public:
  char *strStr(char *haystack, char *needle) {
    vector<int> next = getNext(needle);
    int j = 0;
    char * h= haystack;
    while (*h!='\0') {
      while (j>=0 && *h!=needle[j]) 
        j = next[j];
      h++;
      j++;
      if (needle[j] == '\0') {
        for (int i = 0; i<j;i++) {
          cout<<*h<<endl;
          h--;
        }
        return h;
      }
    }
    return NULL;
  }
};

int main () {
  Solution s;

  char * s1 ;
  char * s2 ;
  char * s3;
  s1 = (char *)malloc(100000);
  s2 = (char *)malloc(10000);
  strcpy(s1,"aaabcabcabcd");
  strcpy(s2,"abcabcabcd");
  s3 = s.strStr(s1,s2);
  string ss(s3);
  cout<<ss<<endl;
}
