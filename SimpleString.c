#include <stdio.h>

int main() {
  char *str = "thisisalongstring";
  char *ptr1 = (char *)&str;// incorrectly assigns address of pointer variable
  char *ptr2 = (char *)&str[0];
  char *ptr3 = &str[0];
  char *ptr4 = str;
  // warning incorrect address of pointer variable.pointer to pointer.
#ifdef __clang_analyzer__
  char *ptr5 = &str;
#endif
  printf("str: %s\n", str);
  printf("ptr1: %s\n", ptr1);
  printf("ptr2: %s\n", ptr2);
  printf("ptr3: %s\n", ptr3);
  printf("ptr4: %s\n", ptr4);
#ifdef __clang_analyzer__
  printf("ptr5: %s\n", ptr5);
#endif
  return 0;
}
