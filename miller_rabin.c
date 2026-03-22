#include <stdio.h>

// Helper to calculate (a^b) % n
long long power(long long a, long long b, long long n) {
    long long res = 1;
    a %= n;
    while (b > 0) {
        if (b % 2 == 1) res = (res * a) % n;
        a = (a * a) % n;
        b /= 2;
    }
    return res;
}

int isPrime(long long n) {
    // Basic checks
    if (n < 2) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0) return 0;

    // Step 1: Find n-1 = 2^k * m
    long long m = n - 1;
    int k = 0;
    while (m % 2 == 0) {
        m /= 2;
        k++;
    }

    // Step 2: Choose a (using a=2 for simplicity)
    long long a = 2; 

    // Step 3: Compute b0 = a^m % n
    long long b = power(a, m, n);

    // If b0 is 1 or -1 (n-1), it's probably prime
    if (b == 1 || b == n - 1) return 1;

    // Step 4: Keep squaring b
    for (int i = 1; i < k; i++) {
        b = (b * b) % n;
        if (b == n - 1) return 1; // Found -1, probably prime
        if (b == 1) return 0;     // Hit 1 too early, composite
    }

    return 0; // Never hit -1, composite
}

int main() {
    long long n;
    printf("Enter number: ");
    scanf("%lld", &n);

    if (isPrime(n)) printf("Prime\n");
    else printf("Composite\n");

    return 0;
}