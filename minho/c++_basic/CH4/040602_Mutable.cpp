#include <iostream>

class A {
    mutable int data_; // const 함수 안에서 해당 멤버 변수에 const가 아닌 작업 가능

    public:
        A(int data) : data_(data) {}
        void DoSomething(int x) const {
            data_ = x; 
        }

        void PrintData() const { std::cout << "data : " << data_ << "\n"; }
};


int main()
{
    A a(10);
    a.DoSomething(3);
    a.PrintData();
}