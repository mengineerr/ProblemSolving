#include <iostream>
#include <string>

int main()
{
    std::string str;
    getline(std::cin,str);

    int len = str.length();
    int time = 0;

    for(int i=0; i<len;i++){
        if(str[i]>='A' && str[i]<='C'){
            time += 3;
        }
        else if(str[i]>='D' && str[i]<='F'){
            time += 4;
        }
        else if(str[i]>='G' && str[i]<='I'){
            time += 5;
        }
        else if(str[i]>='J' && str[i]<='L'){
            time += 6;
        }
        else if(str[i]>='M' && str[i]<='O'){
            time += 7;
        }
        else if(str[i]>='P' && str[i]<='S'){
            time += 8;
        }
        else if(str[i]>='T' && str[i]<='V'){
            time += 9;
        }
        else if(str[i]>='W' && str[i]<='Z'){
            time += 10;
        }
    }

    std::cout << time <<"\n";
}