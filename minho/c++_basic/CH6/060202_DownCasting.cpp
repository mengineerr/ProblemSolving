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
    
    //Cannot Do it. It points out of scope

    /*  Ver1
    Derived* p_p = &p;      
    */

    /*  Ver2
    Base* p_p = &c;
    Derived* p_c = p_p;
    p_c->what();
    */
}