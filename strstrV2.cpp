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
    if (*needle == '\0') return haystack;
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
          h--;
        }
        return h;
      }
    }
    return NULL;
  }
};
