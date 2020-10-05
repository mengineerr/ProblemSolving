#include <iostream>

int main()
{
    int num,cnt = 0;
    int value = 0;

    for(int i=0;i<9;i++){
        std::cin >> num;

        if(num>value){
            value = num;
            cnt = i+1;
        }
    }

    std::cout << value << "\n" << cnt << std::endl;
}