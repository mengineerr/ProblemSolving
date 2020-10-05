#include <iostream>

int main() 
{
    int a,b,c = 0;

    std::cin >> a >> b >> c;

    if(a>=b&&b>=c) std::cout << b << std::endl;
    else if (a>=c&&c>=b) std::cout << c << std::endl;
    else if (b>=a&&a>=c) std::cout << a << std::endl;
    else if (b>=c&&c>=a) std::cout << c << std::endl;
    else if (c>=a&&a>=b) std::cout << a << std::endl;
    else  std::cout << b << std::endl;

    return 0;
}