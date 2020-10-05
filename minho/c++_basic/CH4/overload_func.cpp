#include <iostream>

// overload 로 동일한 함수 이름 사용 가능
void print(int x) { std::cout << "int : "<< x << std::endl;}
void print(double x) { std::cout << "double : "<< x << std::endl;}

int main()
{
    int a = 1;
    char b = 'c';
    double c = 3.2f;

    print(a);
    print(b); // Overloading 과정으로 근사치 출력
    print(c);
    // Overloading 규칙 숙지!

    return 0;
}