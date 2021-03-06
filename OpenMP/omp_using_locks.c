// omp_using_locks.c
// compile with: /openmp /c
#include <omp.h>
#include <stdio.h>
#include <unistd.h>

void work(int val) { sleep(val); }

void skip(int val) {
  printf("Skipping %d.\n", val);
  sleep(val + 1);
}

int main(int argc, char *argv[]) {
  omp_lock_t lck;
  int id;

  omp_init_lock(&lck);
#pragma omp parallel shared(lck) private(id)
  {
    id = omp_get_thread_num();

    omp_set_lock(&lck);
    printf("My thread id is %d.\n", id);

    // only one thread at a time can execute this printf
    omp_unset_lock(&lck);

    while (!omp_test_lock(&lck)) {
      skip(id);
      // we do not yet have the lock,
      // so we must do something else
    }
    work(id);
    // we now have the lock
    // and can do the work
    omp_unset_lock(&lck);
  }
  omp_destroy_lock(&lck);
}
