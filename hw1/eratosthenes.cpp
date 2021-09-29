#include <bits/stdc++.h>
#include <iostream>
#include <cstdint>
using namespace std;

uint64_t ImprovedEratosthenes(int n)
{
    uint64_t y = 0;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (uint64_t p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (uint64_t i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (uint64_t p = 2; p <= n; p++)
        if (prime[p])

            y++;
    return y;
}

int main()
{
    uint64_t n = 0;

    cout << "Enter a number greater than 1: ";
    cin >> n;
    cout << endl;

    cout << "The sum of prime numbers up to " << n << " is: " << ImprovedEratosthenes(n);
    return 0;
}