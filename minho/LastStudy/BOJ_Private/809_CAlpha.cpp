#include <iostream>
#include <string>

int main()
{
    std::string str;
    getline(std::cin,str);

    int len = str.length();
    int cnt = 0;

    for(int i=0; i<len;i++){
        if(str[i+1]=='-' || str[i+1]=='='){
            i++;
        }
        else if(str[i]=='d'){
            if(str[i+1]=='z') {
                if(str[i+2]=='=') i+=2;
            }
        }
        else if(str[i]=='l'){
            if(str[i+1]=='j') i++;
        }
        else if(str[i]=='n'){
            if(str[i+1]=='j') i++;
        }

        cnt++;
    }

    std::cout << cnt <<"\n";
}