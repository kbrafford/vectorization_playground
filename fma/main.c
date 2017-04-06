#include <stdio.h>
#include "fma.h"

int main(void)
{
  printf("Single precision:\n");

	              /* c     x    x**2 */
  float coeffs[] = {1.0f, 2.0f, 3.0f};
  float x[] = {.2f, .4f, .6f, .8f};
  float results[4];

  printf ("%gx^2 + %gx + %g evaluated at\n%f, %f, %f, %f = \n",
		  coeffs[2],coeffs[1],coeffs[0],
		  x[0],x[1],x[2],x[3]);

  horner_fma_sp(x, coeffs, 3, results);

  printf("%f, %f, %f, %f\n", results[0],results[1], results[2], results[3]);

  printf("\nDouble precision:\n");

                      /* c    x   x**2 */
  double coeffs_dp[] = {1.0, 2.0, 3.0};
  double x_dp[] = {1.0/3.0, 2.0/3.0};
  double results_dp[2];

  printf ("%gx^2 + %gx + %g evaluated at\n%f, %f = \n",
                       coeffs_dp[2],coeffs_dp[1],coeffs_dp[0], x_dp[0],x_dp[1]);

  horner_fma_dp(x_dp, coeffs_dp, 3, results_dp);

  printf("%f, %f\n", results_dp[0], results_dp[1]);

  return 0;
}

