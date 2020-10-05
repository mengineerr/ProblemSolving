#include <iostream>

int fn1(int &a) { return a; }
int &fn2(int &a) { return a; }

int main()
{
    int lucky_number = 3;
    std::cout << "write my secret number " << std::endl;

    int user_input;

    while(1){
        std::cout << "input : ";
        std::cin >> user_input;
        if(lucky_number == user_input){
            std::cout << "Write!" << std::endl;
            break;
        }
        else{
            std::cout << "Input Again" << std::endl;
        }
    }

    std::cout << std::endl;

    //-----------------------------------------------------------------
    int x = 1;
    std::cout << fn2(x)++ << std::endl;
    std::cout << "x : " << x << std::endl;


    return 0;
}
