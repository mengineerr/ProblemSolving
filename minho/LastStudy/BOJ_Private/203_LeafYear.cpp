#include <iostream>

int main()
{
    int a = 0;

    std::cin >> a ;

    if((a%4)==0){
        if((a%400)==0) std::cout << "1" << std::endl;
        else if((a%100)==0) std::cout << "0" << std::endl;
        else std::cout << "1" << std::endl;
    }
    else std::cout << "0" << std::endl;

    return 0;
}