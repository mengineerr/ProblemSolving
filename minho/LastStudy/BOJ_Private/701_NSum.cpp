#include <iostream>

int sum(int &num){
    int sum =0;
    int temp = 0;
    for(int i=0;i<num;i++){
        std::cin >> temp;
        sum += temp;
    }

    return sum;
}

int main()
{
    int n=0;
    
    std::cin >> n;

    std::cout<<sum(n)<<"\n";

}