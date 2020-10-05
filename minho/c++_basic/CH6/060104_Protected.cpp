#include <iostream>
#include <string>

class Base{
    protected:  //상속까지 변수 이용가능
        std::string parent_string;

    public:
        Base() : parent_string("기반") {
            std::cout << "기반 클래스\n";
        }

        void what() {
            std::cout << parent_string << "\n";
        }
};

class Derived : public Base{
    std::string child_string;

    public:
        Derived() : child_string("파생"), Base() {
            std::cout << "파생 클래스\n";

            parent_string = "바꾸기"; //private 변수는 상속해도 사용 불가
        }

        void what() {
            std::cout << child_string << "\n";
        }
};

int main()
{
    std::cout << "=== 기반 클래스 생성 ===\n";
    Base p;

    std::cout << "=== 파생 클래스 생성 ===\n";
    Derived c;

    return 0;
}