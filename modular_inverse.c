#include <stdio.h>

// Function to compute gcd and modular inverse using Extended Euclidean Algorithm
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) return 0; // Modular inverse doesn't exist if m = 1

    while (a > 1) {
        // q is quotient
        q = a / m;
        t = m;

        // m is remainder now, process same as Euclid's algorithm
        m = a % m;
        a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

int main() {
    int a, m;
    printf("Enter number (a): ");
    scanf("%d", &a);
    printf("Enter modulus (m): ");
    scanf("%d", &m);

    int inv = modInverse(a, m);
    if ((a * inv) % m == 1)
        printf("Modular inverse of %d modulo %d is %d\n", a, m, inv);
    else
        printf("Modular inverse does not exist for %d modulo %d\n", a, m);

    return 0;
}