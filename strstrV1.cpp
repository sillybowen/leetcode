class Solution {
  
public:
  char *strStr(char *haystack, char *needle) {
    
    if (haystack == NULL||needle==NULL) return NULL;
    if (*haystack=='\0' && *needle == '\0') return haystack;
    char * h1 = haystack;
    char * h2;
    char * h;
    while (*h1!='\0') {
      
      h = h1;
      h2 = needle;
      while (*h1!='\0' && *h2!='\0' && *h1 == *h2) {
        
        h1++;
        h2++;
      } 
            
      if (*h2 =='\0')
        return h;
      h1 = h;
      h1++;
    }
    return NULL;
  }
};
