#include <stdio.h>

int main()
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n <= 1)
    {
        printf("%d is not a prime number.\n", n);
    }
    else
    {
        int isPrime = 1; // Assume n is prime
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                isPrime = 0; // n is divisible by i, so it's not prime
            }
        }
        if (isPrime)
        {
            printf("%d is a prime number.\n", n);
        }
        else
        {
            printf("%d is not a prime number.\n", n);
        }
    }

    return 0;
}