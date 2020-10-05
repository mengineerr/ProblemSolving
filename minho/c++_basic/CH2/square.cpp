#include <iostream>

void print_square(int arg);


int main()
{
    int i;

    std::cout << "Square Input : ";
    std::cin >> i;

    print_square(i);

    return 0;
}

void print_square(int arg){
    std::cout << "Output is : " << arg * arg << std::endl;
}
