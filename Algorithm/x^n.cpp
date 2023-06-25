#include <iostream>

// Function to calculate the power using divide and conquer
double power(double x, int n)
{
    if (n == 0)
        return 1;

    double temp = power(x, n / 2);
    double result = temp * temp;

    if (n % 2 == 1)
        result *= x;

    return result;
}

// Test the code
int main()
{
    double x = 2;
    int n = 4;

    double result = power(x, n);

    std::cout << x << " raised to the power " << n << " is: " << result << std::endl;

    return 0;
}
