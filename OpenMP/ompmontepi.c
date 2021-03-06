#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  double niter = 10000000;
  double x, y;
  int i;
  int count = 0;
  double z;
  double pi;
  srand(time(NULL));
#pragma omp parallel private(i, x, y, z) shared(count)
  {
#pragma omp for reduction(+ : count) schedule(static)
    for (i = 0; i < niter; ++i) {
      // get random points
      x = (double)random() / RAND_MAX;
      y = (double)random() / RAND_MAX;
      z = sqrt((x * x) + (y * y));
      // check to see if point is in unit circle
      if (z <= 1) {
        ++count;
      }
    }
  }
  pi = ((double)count / (double)niter) * 4.0; // p = 4(m/n)
  printf("Pi: %f\n", pi);
}
