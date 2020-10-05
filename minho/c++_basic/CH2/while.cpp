#include <iostream>



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

    return 0;
}
