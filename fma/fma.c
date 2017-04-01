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


/*
 *   Horner's Method for polynomial evaluation
 *   Mostly glommed from:
 *   https://en.wikipedia.org/wiki/Horner%27s_method
 */

/*
 *   AVX
 */
inline static __m128 _fma_ff_vec(__m128 *veca, __m128 *vecb, float C)
{
  __m128 vecc = _mm_set1_ps(C);
  return _mm_fmadd_ps(*veca, *vecb, vecc);
}

void horner_fma_sp(float *x, float *coeffs, unsigned int count, float *res)
{
  __m128 vec_x = _mm_set_ps(x[3], x[2], x[1], x[0]);
  __m128 vec_res = _mm_set1_ps(0.0f);

  int idx;
  for (idx = count-1; idx >= 0; idx--)
    vec_res = _fma_ff_vec(&vec_res, &vec_x, coeffs[idx]);

  float *pres = (float*) &vec_res;

  res[0] = pres[0];
  res[1] = pres[1];
  res[2] = pres[2];
  res[3] = pres[3];

  return;
}

inline static __m128d _fma_dd_vec(__m128d *veca, __m128d *vecb, double C)
{
  __m128d vecc = _mm_set1_pd(C);
  return _mm_fmadd_pd(*veca, *vecb, vecc);
}

void horner_fma_dp(double *x, double *coeffs, unsigned int count, double *res)
{
  __m128d vec_x = _mm_set_pd(x[1], x[0]);
  __m128d vec_res = _mm_set1_pd(0.0);

  int idx;
  for (idx = count-1; idx >= 0; idx--)
    vec_res = _fma_dd_vec(&vec_res, &vec_x, coeffs[idx]);

  double *pres = (double*) &vec_res;

  res[0] = pres[0];
  res[1] = pres[1];

  return;
}


/*
 *   AVX2
 */
inline static __m256 _fma_ff_vec_avx2(__m256 *veca, __m256 *vecb, float C)
{
  __m256 vecc = _mm256_set1_ps(C);
  return _mm256_fmadd_ps(*veca, *vecb, vecc);
}

void horner_fma_sp_avx2(float *x, float *coeffs, unsigned int count, float *res)
{
  __m256 vec_x = _mm256_set_ps(x[7], x[6], x[5], x[4], x[3], x[2], x[1], x[0]);
  __m256 vec_res = _mm256_set1_ps(0.0f);

  int idx;
  for (idx = count-1; idx >= 0; idx--)
    vec_res = _fma_ff_vec_avx2(&vec_res, &vec_x, coeffs[idx]);

  float *pres = (float*) &vec_res;

  res[0] = pres[0];
  res[1] = pres[1];
  res[2] = pres[2];
  res[3] = pres[3];
  res[4] = pres[4];
  res[5] = pres[5];
  res[6] = pres[6];
  res[7] = pres[7];

  return;
}

inline static __m256d _fma_dd_vec_avx2(__m256d *veca, __m256d *vecb, double C)
{
  __m256d vecc = _mm256_set1_pd(C);
  return _mm256_fmadd_pd(*veca, *vecb, vecc);
}

void horner_fma_dp_avx2(double *x, double *coeffs, unsigned int count,
                		double *res)
{
  __m256d vec_x = _mm256_set_pd(x[3], x[2], x[1], x[0]);
  __m256d vec_res = _mm256_set1_pd(0.0);

  int idx;
  for (idx = count-1; idx >= 0; idx--)
    vec_res = _fma_dd_vec_avx2(&vec_res, &vec_x, coeffs[idx]);

  double *pres = (double*) &vec_res;

  res[0] = pres[0];
  res[1] = pres[1];
  res[2] = pres[2];
  res[3] = pres[3];

  return;
}
