#include <iostream>

int main()
{
    int a,b,c;
    int arr[10] = {0,};

    std::cin >> a >> b >> c;

    a = a*b*c;
    while(a>0){
        arr[a%10]++;
        a /= 10;
    }

    for(int i =0;i<10;i++){
        std::cout << arr[i] <<"\n";
    }
}