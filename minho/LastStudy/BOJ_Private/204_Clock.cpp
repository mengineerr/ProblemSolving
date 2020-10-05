#include <iostream>

int main()
{
    int a,b =0;

    std::cin >> a >> b ;

    b -= 45;

    if(b>=0) std::cout << a << " " << b <<std::endl;
    else {
        a -= 1;
        b += 60;
        if(a<0) {
            a = 23;
            std::cout << a << " " << b <<std::endl;
        }
        else std::cout << a << " " << b <<std::endl;
    }

    return 0;
}