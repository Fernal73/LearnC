#include <stdio.h>

int main() {
  int x = 7;
  printf("Value of x:%d\n", x);
  // ptr "points" to location of x:
  int *ptr = &x;
  printf("Value of ptr:%d\n", *ptr); // ptr2 points to same location as ptr:
  int *ptr2 = ptr;
  // the address of ptr2 plus one:
  int *ptr3 = ptr2 + 1;
  printf("Value of ptr3: %d\n",
         *ptr3); // uncomment this block to see the error message:
                 int *ptr4 = ptr2+20;
                 printf("Value of ptr4: %d\n", *ptr4);
  return 0;
}
