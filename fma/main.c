#include <stdio.h>
#include "fma.h"

void main(void)
{
  float coeffs[] = {1.0f, 2.0f, 3.0f};
  float x[] = {.2f, .4f, .6f, .8f};
  float results[4];

  printf ("%gx^2 + %gx + %g evaluated at\n%f, %f, %f, %f = \n",
		  coeffs[2],coeffs[1],coeffs[0],
		  x[0],x[1],x[2],x[3]);

  horner_fma_sp(x, coeffs, 3, results);

  printf("%f, %f, %f, %f\n", results[0],results[1], results[2], results[3]);
}

