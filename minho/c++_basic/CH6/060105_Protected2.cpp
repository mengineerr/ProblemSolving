#include <iostream>
#include <string>

class Base{
    
    public:
        std::string parent_string;
        Base() : parent_string("기반") {
            std::cout << "기반 클래스\n";
        }

        void what() {
            std::cout << parent_string << "\n";
        }
};

class Derived : private Base{   //Base 클래스를 private로 받음에 주의!
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
    Base p;
    std::cout << p.parent_string << "\n";

    Derived c;
    //std::cout << c.parent_string << "\n";
    //Derived 클래스에서는 Base 클래스가 private이 되므로 접근 불가

    return 0;
}