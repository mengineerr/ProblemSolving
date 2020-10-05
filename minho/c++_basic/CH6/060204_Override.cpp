#include <iostream>
#include <string>

class Base {
    std::string s;

    public : 
        Base() :s("Base") { std::cout << "Base Class\n" ;}

        virtual void what() { std::cout << s << "\n"; }
        //It called Virtual Function. Relevant functions should be same form.
};

class Derived : public Base {
    std::string s;

    public:
        Derived() : s("Derived") { std::cout << "Derived Class\n";}

        void what() override { std::cout << s << "\n";}
};

int main()
{
    Base p;
    Derived c;

    Base* p_c = &c;
    Base* p_p = &p;

    //Example of Dynamic Binding!!
    std::cout << "===Actual Object is Base Object\n";
    p_p->what();

    std::cout << "===Actual Object is Derived Object\n";
    p_c->what();
    

}