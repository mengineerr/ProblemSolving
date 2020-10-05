#include <iostream>

int main()
{
    int a,b = 0;

    std::cin >> a >> b;

    int arr[a] ;

    for(int i = 0; i<a ;i++){
        std::cin >> arr[i];
    }

    for(int i = 0; i<a ;i++){
        if(arr[i]<b) std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}