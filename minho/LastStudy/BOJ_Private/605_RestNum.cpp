#include <iostream>

int main()
{
    int arr[10];
    int arr2[42] = {0,};
    int cnt = 0;

    for(int i =0 ;i<10;i++){
        std::cin >> arr[i];
        arr[i] %= 42;
    }

    for(int i =0 ;i<10;i++){
        arr2[arr[i]]++;
    }

    for(int i = 0; i<42;i++){
        if(arr2[i]>=1) cnt++;
    }

    std::cout << cnt << "\n";

}