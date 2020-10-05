#include <iostream>

class Int{
    int data;

    public:
        Int(int data) : data(data){}
        Int(const Int& i) : data(i.data) {}

        operator int() {return data;}
};

class Test {
    int x;

    public:
        Test(int x) : x(x) {}
        Test(const Test& t) : x(t.x) {}

        Test& operator++(){
            x++;
            std::cout << "전위 증감 연산자" << "\n";
            return *this;
        }

        Test operator++(int) {
            Test temp(*this);
            x++;
            std::cout << "후위 증감 연산자\n";
            return temp;
        }

        int get_x() const {
            return x;
        }
};

void func(const Test& t) {
    std::cout << "x : " << t.get_x() << "\n";
}

int main()
{
    Int x = 3;
    int a = x + 4;

    x = a * 2 + 4;
    std::cout << x <<"\n";

    Test t(3);

    func(++t);
    func(t++);
    std::cout << "x : " << t.get_x() << "\n";
}