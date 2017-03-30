void fma_ff(float *A, float *B, float C, float *res);
void fma_dd(double *A, double *B, double C, double *res);

void horner_fma_sp(float *x, const float *coeffs, unsigned int count, float *res);
void horner_fma_dp(double *x, const double *coeffs, unsigned int count, double *res);
