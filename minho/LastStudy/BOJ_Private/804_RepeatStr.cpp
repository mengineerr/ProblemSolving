#include <iostream>
#include <string>

int main()
{
    int test = 0;
    int num = 0;

    std::cin >> test;

    

    for(int k=0;k<test;k++){
        
        std::cin >> num;

        std::string str;
        std::cin >> str;
        
        int len = str.length();

        char result[len*num];
        result[0] ={0,};

        for(int i = 0; i<len; i++){
            for(int j = 0; j<num;j++){
                result[num*i+j] = str.at(i);
                //std::cout << result[num*i+j] <<str.at(i) <<"\n";
            }
        }

        for(int i = 0 ; i<len*num;i++){
            std::cout << result[i];
        }
        
        std::cout << "\n";
    }

}