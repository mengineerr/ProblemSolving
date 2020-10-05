#include <iostream>

int main() 
{
    int a,b,c = 0;

    std::cin >> a;

    for(int i = 0; i<a; i++){
        std::cin >> b >> c;
        std::cout << b + c << std::endl;
    }

    return 0;
}