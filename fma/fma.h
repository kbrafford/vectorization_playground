float fma_ff(float A, float B, float C);
float fma_fd(double A, double B, double C);
double fma_dd(double A, double B, double C);
float x87fma_ff(float A, float B, float C);
float x87fma_fd(double A, double B, double C);
double HornerEvaluate (double x, double * CoefficientsOfPolynomial, unsigned int DegreeOfPolynomial);
float HornerEvaluate_sp (float x, float *CoefficientsOfPolynomial, unsigned int DegreeOfPolynomial);
float horner_fma_sp(float x, const float *coeffs, unsigned int count);
double horner_fma_dp(double x, const double *coeffs, unsigned count);
