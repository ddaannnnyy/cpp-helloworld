#include <iostream>
#include <cmath>

int main()
{
    double a;
    double b;
    double c;

    // input for sides a and b
    std::cout << "Enter side A:";
    std::cin >> a;
    std::cout << "Enter side B:";
    std::cin >> b;

    // pythag the long way
    a = pow(a, 2);
    b = pow(b, 2);
    c = sqrt(a + b);

    // pythag a short way
    //  c = sqrt(pow(a, 2) + pow(b, 2));

    // output value
    std::cout << "side C: " << c << '\n';

    return 0;
}