#include <immintrin.h>

float fma_ff(float A, float B, float C)
{
  __m128 veca = _mm_set1_ps(A);
  __m128 vecb = _mm_set1_ps(B);
  __m128 vecc = _mm_set1_ps(C);
  __m128 result = _mm_fmadd_ps(veca, vecb, vecc);

  float *res = (float*) &result;

  return res[0];
}

float fma_fd(double A, double B, double C)
{
  __m128d veca = _mm_set1_pd(A);
  __m128d vecb = _mm_set1_pd(B);
  __m128d vecc = _mm_set1_pd(C);
  __m128d result = _mm_fmadd_pd(veca, vecb, vecc);

  double *res = (double*) &result;

  return (float)(res[0]);
}
