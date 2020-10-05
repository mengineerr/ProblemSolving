#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;

    int len = str.length();
    int alpha[26] ={0,};

    for(int i =0; i<len ; i++){
        if(str.at(i)>='A' && str.at(i)<='Z') alpha[str.at(i)-'A']++;
        else{
            alpha[str.at(i)-'a']++;
        }
    }

    int idx_max = 0;
    int cnt = 0;

    for(int i = 0; i<26; i++){
        if(alpha[i]>cnt){
            cnt = alpha[i];
            idx_max = i;
        }
        else;
    }

    for(int i = 0; i<26; i++){
        if(alpha[i]==cnt && i!=idx_max){
            cnt = -1;
            break;
        }
    }  

    if(cnt==-1) std::cout << "?\n";
    else std::cout << (char)(idx_max+'A') << "\n";
}