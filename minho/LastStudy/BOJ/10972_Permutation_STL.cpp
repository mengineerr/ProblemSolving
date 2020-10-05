#include <iostream>
#include <algorithm>

int main()
{
    int N = 0;
    std::cin >> N;
    
    int num[10000];

    for(int i = 0; i < N; i++){
        std::cin >> *(num+i);
    }

    if(std::next_permutation(num,num+N) == true){
        for(int i = 0; i < N; i++){
            std::cout << num[i] << " ";
        }
        std::cout << "\n";
    }
    else{
        std::cout << "-1\n";
    }

}