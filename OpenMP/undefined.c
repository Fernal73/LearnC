#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int i, j;
  i = 1;
  (void)i;
  j = 2;
#pragma omp parallel private(i) firstprivate(j)
  {
    i = 3;
    j = j + 2;
  }
  printf("%d %d\n", i, j);
}
