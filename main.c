#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

static double timestamp() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + ((double)tv.tv_usec)*1e-6;
}

void bpu_history(volatile uint64_t *acc,
		 uint32_t seed,
		 uint64_t iters,
		 uint64_t len);


int main() {
  uint64_t acc = 0;
  static const uint64_t iters = 1UL<<28, max_len = 1UL<<16, stride = 128;
  
  for(uint64_t len = stride; len <= max_len; len += stride) {
    acc = 0;
    double t0 = timestamp();
    bpu_history(&acc, 1, iters, len);
    t0 = timestamp() - t0;
    printf("%llu, %g\n", len, t0/iters);
    //printf("acc/iters = %g\n", ((double)acc)/iters);
  }
  return 0;
}
