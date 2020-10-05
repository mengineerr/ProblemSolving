#include <iostream>

int main()
{
    int b,c=0;

    while(1){
        std::cin >> b >> c;
        std::cout << b+c << std::endl;
        
        if(b==EOF||c==EOF) break;
    }

    
}