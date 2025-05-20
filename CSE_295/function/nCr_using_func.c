#include <stdio.h>

long long int factorial(long long int n) {
    long long int fact = 1;
    for (long long int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main(){
    long long int n, r;
    printf("Enter n and r: ");
    scanf("%lld %lld", &n, &r);
    if (n < 0 || r < 0 || r > n) {
        printf("Invalid input. Please enter non-negative integers with r <= n.\n");
        return 1;
    }
    long long int nFact = factorial(n);
    long long int rFact = factorial(r);
    long long int n_rFact = factorial(n - r);
    long long int nCr = nFact / (rFact * n_rFact);
    printf("nCr = %lld\n", nCr);
    return 0;
}