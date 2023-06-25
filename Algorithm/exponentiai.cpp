#include <iostream>

// Function to calculate modular exponentiation (base^exp % mod) using divide and conquer
int modularExponentiation(int base, int exp, int mod)
{
    if (exp == 0)
        return 1;

    // Divide the exponent by 2 and calculate modular exponentiation recursively
    int result = modularExponentiation(base, exp / 2, mod);
    result = (result * result) % mod;

    // If the exponent is odd, multiply the result by the base once more
    if (exp % 2 != 0)
        result = (result * base) % mod;

    return result;
}

// Test the code
int main()
{
    int base = 5;
    int exp = 3;
    int mod = 1000000007;

    int result = modularExponentiation(base, exp, mod);

    std::cout << base << "^" << exp << " % " << mod << " = " << result << std::endl;

    return 0;
}
