#include <iostream>
#include <string>

class Base {
    std::string s;

    public :
        Base() : s("기반") { 
            std::cout << "기반 클래스" << "\n";
        }

        void what() {
            std::cout << s << "\n";
        }
};

class Derived : public Base {
    std::string s;

    public :
        Derived() : Base(), s("파생"){
            std::cout << "파생 클래스" << "\n";

            what(); // Base 클래스의 what과 Derived 클래스의 what 중에서는 현재 클래스 함수 우선 사용
                    // 이를  Overriding 이라 함
        }

        void what() { std::cout << s << "\n"; }
};

int main()
{
    std::cout << "=== 기반 클래스 생성 ===\n";
    Base p;

    std::cout << "=== 파생 클래스 생성 ===\n";
    Derived c;

    return 0;
}