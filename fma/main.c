#include <stdio.h>
#include "fma.h"

void main(void)
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

/*
 *  AVX2
 */
  /* taylor series for sin */
  float coeffs_sp_avx2[] = { 0.0f,                  /* c   */
                             1.0f,                  /* x   */
					         0.0f,                  /* x^2 */
					         -1.0/(3*2),            /* x^3 */
				  	         0.0f,                  /* x^4 */
		  			         1.0/(5*4*3*2),         /* x^5 */
	  				         0.0f,                  /* x^6 */
					         -1.0/(7*6*5*4*3*2),    /* x^7 */
					         0.0f,                  /* x^8 */
							 1.0/(9*8*7*6*5*4*3*2)  /* x^9 */
                           };

  /* create an array of all of the X positions to evaluate */
#define _TAU (2.0*3.14159265359)
  float x_sp_avx2[] = { -_TAU * (3. / 8.0),
		                -_TAU * (2. / 8.0),
		                -_TAU * (1. / 8.0),
 		                 _TAU * (0. / 8.0),
 		                 _TAU * (1. / 8.0),
		                 _TAU * (2. / 8.0),
		                 _TAU * (3. / 8.0),
		                 _TAU * (4. / 8.0),
                      };
  float results_sp_avx2[8];

  horner_fma_sp_avx2(x_sp_avx2, coeffs_sp_avx2,
		             sizeof(coeffs_sp_avx2)/sizeof(coeffs_sp_avx2[0]),
				     results_sp_avx2);

  float *p = results_sp_avx2;
  printf("\n%f %f %f %f %f %f %f %f\n",
		  p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]);

#undef _TAU
}

