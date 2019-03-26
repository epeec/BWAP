#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <unstickymem/unstickymem.h>

#define SIZE      100 * 1024 * 1024
#define NUM_ELEMS SIZE / sizeof(int)

int main() {
  printf("Hello world\n");
 // unstickymem_nop();
  int *x = malloc(SIZE);
  x[0] = 123;
  unstickymem_start();
  for(size_t i=1; i < NUM_ELEMS; i++) {
    x[i] = x[0] * x[0] % 1000000;
  }
  sleep(60);
  free(x);
  return 0;
}
