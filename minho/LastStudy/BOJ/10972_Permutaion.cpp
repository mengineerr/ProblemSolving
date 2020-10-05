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

    int idx = N-1;

    while( idx > 0 && num[idx-1] > num[idx] ) idx--;

    if(idx == 0) std::cout << "-1\n";
    else{
        int limit = 10001;
        int loc = 0;
        for(int i = idx; i < N ; i++){
            if(num[idx-1] < num[i] && num[i] < limit){
                limit = num[i];
                loc = i;
            }
        }

        int temp = num[idx-1];
        num[idx -1] = num[loc];
        num[loc] = temp;

        std::sort(num + idx, num + N);

        for(int i = 0; i < N; i++){
            std::cout << num[i] << " ";
        }
    }

}