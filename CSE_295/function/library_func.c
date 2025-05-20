#include <stdio.h>
#include <math.h>


int main(){

    double value = 12.5;

    double sqrt_value = sqrt(value);
    double pow_value = pow(value, 2);
    double log_value = log(value);
    double log10_value = log10(value);
    double exp_value = exp(value);
    double sin_value = sin(value);
    double cos_value = cos(value);
    double tan_value = tan(value);
    double asin_value = asin(value);
    double acos_value = acos(value);
    double atan_value = atan(value);
    double sinh_value = sinh(value);
    double cosh_value = cosh(value);
    double tanh_value = tanh(value);
    double ceil_value = ceil(value);
    double floor_value = floor(value);
    double round_value = round(value);
    double abs_value = fabs(value);

    printf("sqrt(%f) = %f\n", value, sqrt_value);
    printf("pow(%f, 2) = %f\n", value, pow_value);
    printf("log(%f) = %f\n", value, log_value);
    printf("log10(%f) = %f\n", value, log10_value);
    printf("exp(%f) = %f\n", value, exp_value);
    printf("sin(%f) = %f\n", value, sin_value);
    printf("cos(%f) = %f\n", value, cos_value);
    printf("tan(%f) = %f\n", value, tan_value);
    printf("asin(%f) = %f\n", value, asin_value);
    printf("acos(%f) = %f\n", value, acos_value);
    printf("atan(%f) = %f\n", value, atan_value);
    printf("sinh(%f) = %f\n", value, sinh_value);
    printf("cosh(%f) = %f\n", value, cosh_value);
    printf("tanh(%f) = %f\n", value, tanh_value);
    printf("ceil(%f) = %f\n", value, ceil_value);
    printf("floor(%f) = %f\n", value, floor_value);
    printf("round(%f) = %f\n", value, round_value);
    printf("abs(%f) = %f\n", value, abs_value);
    printf("fabs(%f) = %f\n", value, abs_value);
    
    return 0;
}