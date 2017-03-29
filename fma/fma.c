#include <immintrin.h>
#include "fma.h"

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

double fma_dd(double A, double B, double C)
{
  __m128d veca = _mm_set1_pd(A);
  __m128d vecb = _mm_set1_pd(B);
  __m128d vecc = _mm_set1_pd(C);
  __m128d result = _mm_fmadd_pd(veca, vecb, vecc);

  double *res = (double*) &result;

  return (res[0]);
}

float x87fma_ff(float A, float B, float C)
{
	return A * B + C;
}

float x87fma_fd(double A, double B, double C)
{
	return (float) (A * B + C);
}

/*
 *   Horner's Method for polynomial evaluation
 *   Mostly glommed from:
 *   https://en.wikipedia.org/wiki/Horner%27s_method
 */

/*
 *  Serial Horner's method...double precision
 */
double HornerEvaluate (double x, double * CoefficientsOfPolynomial, unsigned int DegreeOfPolynomial)
{
  /*
      We want to evaluate the polynomial in x, of coefficients CoefficientsOfPolynomial, using Horner's method.
      The result is stored in dbResult.
  */
  double dbResult = 0.0;
  int i;
  for(i = DegreeOfPolynomial; i >= 0; i--)
  {
    dbResult = dbResult * x + CoefficientsOfPolynomial[i];
  }
  return dbResult;
}


/*
 *  Serial Horner's method...single precision
 */
float HornerEvaluate_sp (float x, float *CoefficientsOfPolynomial, unsigned int DegreeOfPolynomial)
{
  /*
      We want to evaluate the polynomial in x, of coefficients CoefficientsOfPolynomial, using Horner's method.
      The result is stored in dbResult.
  */
  float fResult = 0.0f;
  int i;
  for(i = DegreeOfPolynomial; i >= 0; i--)
  {
    fResult = fResult * x + CoefficientsOfPolynomial[i];
  }
  return fResult;
}


float horner_fma_sp(float x, const float *coeffs, unsigned int count)
{
  float result = 0.0f;
  int idx;
  for (idx = count-1; idx >= 0; idx--)
    result = fma_ff(result, x, coeffs[idx]);
  return result;
}

double horner_fma_dp(double x, const double *coeffs, unsigned int count)
{
  double result = 0.0;
  int idx;
  for (idx = count-1; idx >= 0; idx--)
    result = fma_dd(result, x, coeffs[idx]);
  return result;
}
