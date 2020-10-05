#include <iostream>

int d(int n)
{
    int temp = 0;
    temp +=n;

    while(n>0){
        temp += n%10;
        n /= 10;
    }

    return temp;
}

int main()
{
    int num = 50;
    int arr[10001] = {0,};
    int temp = 0;

    for(int i = 1; i<10000; i++){
        temp=i;
        while(d(temp)<10000){
            arr[d(temp)]++;
            temp = d(temp);
        }
    }

    for(int i = 1; i<10000; i++){
        if(arr[i]==0) std::cout << i << std::endl;
    }
}