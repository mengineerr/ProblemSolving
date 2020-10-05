#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;

    int alpa[26];

    for(int i = 0; i<26; i++){
        alpa[i] = -1;
    }

    int len = str.length();

    for(int i = 0; i<len; i++){
        if(alpa[str[i]-'a']!=-1) continue;
        else alpa[str[i]-'a'] = i;
    }

    for(int i = 0; i<26; i++){
        std::cout << alpa[i] << " ";
    }
    std::cout << "\n";

}