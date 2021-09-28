#include <iostream>
#include <cstdint>

using namespace std;

uint64_t gcd(uint64_t a, uint64_t b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    uint64_t a = 0;
    uint64_t b = 0;

    cout << "Enter the first number: ";
    cin >> a;
    cout << endl;

    cout << "Enter the second number: ";
    cin >> b;
    cout << endl;

    cout << "The GCD is: " << gcd(a, b);

    return 0;
}
