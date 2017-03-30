#include <immintrin.h>
#include "fma.h"

void fma_ff(float *A, float *B, float C, float *res)
{
  __m128 veca = _mm_set_ps(A[0], A[1], A[2], A[3]);
  __m128 vecb = _mm_set_ps(B[0], B[1], B[2], B[3]);
  __m128 vecc = _mm_set1_ps(C);
  __m128 result = _mm_fmadd_ps(veca, vecb, vecc);

  float *pres = (float*) &result;

  res[0] = pres[0];
  res[1] = pres[1];
  res[2] = pres[2];
  res[3] = pres[3];

  return;
}

void fma_dd(double *A, double *B, double C, double *res)
{
  __m128d veca = _mm_set_pd(A[0], A[1]);
  __m128d vecb = _mm_set_pd(B[0], B[1]);
  __m128d vecc = _mm_set1_pd(C);
  __m128d result = _mm_fmadd_pd(veca, vecb, vecc);

  double *pres = (double*) &result;

  res[0] = pres[0];
  res[1] = pres[1];

  return;
}


/*
 *   Horner's Method for polynomial evaluation
 *   Mostly glommed from:
 *   https://en.wikipedia.org/wiki/Horner%27s_method
 */

/*
 *  Serial Horner's method...double precision
 */

void horner_fma_sp(float *x, const float *coeffs, unsigned int count, float *res)
{
  res[0] = res[1] = res[2] = res[3] = 0.0f;
  int idx;
  for (idx = count-1; idx >= 0; idx--)
    fma_ff(res, x, coeffs[idx], res);

  return;
}

void horner_fma_dp(double *x, const double *coeffs, unsigned int count, double *res)
{
  res[0] = res[1] = 0.0;
  int idx;
  for (idx = count-1; idx >= 0; idx--)
    fma_dd(res, x, coeffs[idx], res);

  return;
}
