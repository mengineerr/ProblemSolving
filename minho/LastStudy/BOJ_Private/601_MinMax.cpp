#include <iostream>

int main()
{
    int n,min,max,temp = 0;

    std::cin >> n;

    for(int i=0; i<n;i++){
        std::cin >> temp;
        if(temp>max) max = temp;
        if(temp<min) min = temp;
    }

    std::cout << min << " " << max <<std::endl;

    return 0;
}