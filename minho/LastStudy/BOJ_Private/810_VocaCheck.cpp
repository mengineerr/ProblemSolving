#include <iostream>
#include <string>

int main()
{
    int N = 0;
    std::cin >> N;

    std::string str;

    
    int len = 0;
    int check = 0;
    int result = 0;

    for(int i =0; i<N ; i++){
        int alpha[26] = {0,};
        check = 1;

        std::cin >> str;
        len = str.length();

        for(int j = 0 ; j<len ; j++){
            if(alpha[str[j]-'a']!=0 && str[j] != str[j-1]){
                check = -1;
                //std::cout << "do\n";
            }
            else if(j == 0){
                alpha[str[j]-'a']++;
            }
            else alpha[str[j]-'a']++;
        }

        if(check == -1);
        else{
            result++;
        }
    }

    std::cout << result << "\n";
}