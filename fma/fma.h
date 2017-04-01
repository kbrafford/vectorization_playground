void fma_ff(float *A, float *B, float C, float *res);

void horner_fma_sp(float *x, float *coeffs, unsigned int count, float *res);
void horner_fma_dp(double *x, double *coeffs, unsigned int count, double *res);

void horner_fma_sp_avx2(float *x, float *coeffs, unsigned int count,
		                float *res);
void horner_fma_dp_avx2(double *x, double *coeffs, unsigned int count,
		                double *res);
