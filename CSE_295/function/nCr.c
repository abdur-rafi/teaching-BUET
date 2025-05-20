#include <stdio.h>

int main(){
    long long int n, r;
    printf("Enter n and r: ");
    scanf("%lld %lld", &n, &r);
    if (n < 0 || r < 0 || r > n) {
        printf("Invalid input. Please enter non-negative integers with r <= n.\n");
        return 1;
    }
    long long int nFact = 1;

    // calculate n!
    for (long long int i = 1; i <= n; i++) {
        nFact *= i;
    }

    // calculate r!. we are repeating the same code as above.
    long long int rFact = 1;
    for (long long int i = 1; i <= r; i++) {
        rFact *= i;
    }
    // calculate (n-r)!. Again we are repeating the same code as above.
    long long int n_rFact = 1;
    for (long long int i = 1; i <= n - r; i++) {
        n_rFact *= i;
    }
    long long int nCr = nFact / (rFact * n_rFact);
    printf("nCr = %lld\n", nCr);
    return 0;
}