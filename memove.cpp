#include<stdio.h>
void memove(char * dest, char* src, int len) {
  if (dest == src) return;
  if (dest<src) {
    for (int i=0; i<len; i++) {
      *dest = *src;
      dest++;
      src++;
    }
    return;
  }

  for (int i = len;i>0;i--) {
    *(dest+i-1) = *(src+i-1);
  }
}
int main() {
  char str[] =  "memmove can be very useful......";
  memove (str+20,str+15,11);
//  memove (str+15,str+20,11);
  printf("%s\n",str);
}
