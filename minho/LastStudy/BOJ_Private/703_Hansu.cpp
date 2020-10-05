#include <iostream>



int main()
{
    int N = 0;
    int result = 0;

    std::cin >> N;

    if(N<100){
        result = N;
    }
    else{
        result = 99;
        for(int i=1;i<=9;i++){
            for(int j=-5;j<5;j++){
                if(100*i+10*(i+j)+(i+2*j)<=N && (i+2*j)>=0 && (i+2*j)<10) result++;
            }
        }
    }

    std::cout << result <<"\n";
}