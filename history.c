#include <stdint.h>
#include <stdio.h>

void bpu_history(volatile uint64_t *acc,
		 uint32_t seed,
		 uint64_t iters,
		 uint64_t len) {
  uint64_t i = 0, m, b;
  uint32_t x = seed;
  
  do {

    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;

    b = x & 1;

    /* this remains a branch */
    if(b) {
      *acc = *acc + 1;
    }

    /* masked logic to avoid
     * branches */
    i++;
    m = ((i == len) - 1);
    x = (m & x) | ((~m) & seed);
    i = m & i;

    
    --iters;
  }
  while(iters);
  
}
