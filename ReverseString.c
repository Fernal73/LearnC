#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *ptr1 = "this is a string";
  char *ptr2;
  int len = strlen(ptr1);
  ptr2 = (char *)malloc(len+1);
// ensure that ptr2 is terminated with null character with extra byte.
  strncpy(ptr2,ptr1,len+1);
  for (int i = 0; i < len; i++) {
    *(ptr2 + len - 1 - i) = *(ptr1 + i);
  }
  printf("Original: %s\n", ptr1);
  printf("Reverse: %s\n", ptr2);
}
