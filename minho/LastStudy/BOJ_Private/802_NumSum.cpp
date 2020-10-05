#include <iostream>

int main()
{
    int N = 0;
    std::cin >> N;

    char num[N];
    std::cin >> num;

    int sum = 0;

    for(int i = 0; i<N;i++){
        sum += num[i]-'0';
    }

    std::cout << sum << "\n";
}