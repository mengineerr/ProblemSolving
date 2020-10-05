#include <iostream>

int main()
{
    int a = 0;

    std::cin >> a ;

    if(90<=a&&a<=100) {std::cout << "A" <<std::endl;}
    else if(80<=a&&a<=89) {std::cout << "B" <<std::endl;}
    else if(70<=a&&a<=79) {std::cout << "C" <<std::endl;}
    else if(60<=a&&a<=69) {std::cout << "D" <<std::endl;}
    else if(0<=a&&a<=59) {std::cout << "F" <<std::endl;}
    else {std::cout << "Wrong Number" <<std::endl;}

    return 0;
}