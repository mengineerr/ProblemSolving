#include <iostream>
#include <string>

class Base {
    std::string s;

    public : 
        Base() :s("Base") { std::cout << "Base Class\n" ;}

        void what() { std::cout << s << "\n"; }
};

class Derived : public Base {
    std::string s;

    public:
        Derived() : s("Derived") { std::cout << "Derived Class\n";}

        void what() { std::cout << s << "\n";}
};

int main()
{
    Base p;
    Derived c;

    std::cout << "===Pointer Version===\n";
    Base* p_c = &c;     // Important Things : Pointer points only Base part in Derived Class
    p_c->what();
}