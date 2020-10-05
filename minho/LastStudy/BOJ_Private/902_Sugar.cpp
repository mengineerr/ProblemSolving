#include <iostream>

int main()
{
    int N = 0;

    std::cin >> N;

    int max5 = N/5;
    int temp = max5;
    int j = 0;

    //std::cout << max5 << "\n";
    for(int i=temp;i>=0;i--){
        j = 0;
        if(5*i == N) {
            std::cout << i + j <<"\n";
            return 0; 
        }

        while(5*i+3*j != N){
            j++;
            if(5*i + 3*j == N){
                std::cout << i + j <<"\n";
                return 0;
            }
            else if(5*i+3*j > N) break;
        }
    }
    
    std::cout << -1 << "\n";

    return 0;
}