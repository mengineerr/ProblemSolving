#include <iostream>
#include <string>

int main()
{
    int N = 0;
    std::cin >> N;

    int test = 0;
    std::string str;
    int strLen = 0;

    for(int i = 0; i < N ; i++){
        test = 0;
        std::cin >> str;
        strLen = str.length();
        int j = 0;
        
        
        for(int j = 0; j < strLen; j++){
            if(str[j] == '('){
                test++;
            }
            else if(str[j] == ')'){
                test--;
            }

            if(test < 0){
                break;
            }
        }
        

        if(test == 0){
            std::cout << "YES\n";
        }
        else{
            std::cout << "NO\n";
        }
    }
}