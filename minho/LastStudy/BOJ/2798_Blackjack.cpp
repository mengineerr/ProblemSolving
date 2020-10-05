#include <iostream>
#include <algorithm>

int main()
{
    int N = 0, M = 0;

    std::cin >> N >> M;

    int *card = new int[N];

    for(int i = 0; i<N; i++){
        std::cin >> card[i];
        if(card[i] > 100000) return 0;
    }

    std::sort(card,card+N);

    int temp = 0, result = 0;

    //Brute Force Method
    //How about use mid index for optimization?
    for(int i = 0; i < N-2;i++){
        for(int j = i+1; j < N-1; j++){
            for(int k = j+1; k < N; k++){
                temp = card[i] + card[j] + card[k];
                if(temp > result && temp <= M) result = temp;
                if(result == M) {
                    std::cout << result << "\n";
                    return 0;
                }
            }
        }
    }

    std::cout << result << "\n";

    return 0;

}