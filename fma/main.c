#include <stdio.h>
#include "fma.h"

void main(void)
{
  float A = 12.25e-13f;
  float B = 1.2e-8f;
  float C = 5.25e-1f;

  printf("Traditional answer is: %f\n", A*B + C);
  printf("Fused answer is:       %f\n", fma_ff(A, B, C));
}

