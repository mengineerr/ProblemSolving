#include <iostream>

int main()
{
    int a,b,c,temp,cnt = 0;

    std::cin >> a;
    temp = a;

    while(1){
        
        if(a<10) b = 0;
        else b = a/10;

        c = a%10;
        a = c*10 + (b+c)%10;
        cnt++;

        if(temp == a) break;
    }

    std::cout << cnt << std::endl;
    
    
}