#include <iostream>
#define Max(X, Y) (X) > (Y) ? (X) : (Y)

int main()
{
    std::cin.sync_with_stdio(false);

    int N = 0;
    std::cin >> N;
    int ans = 0;

    // Don't forget : index (1 ~ N+1)
    int plan[N+2][2] = {0,};
    long long dp[N+2] = {0,};

    for(int i = 1; i <= N; i++){
        std::cin >> plan[i][0] >> plan[i][1];
    }

    for(int i = 1; i <= N+1; i++){
        ans = Max(ans, dp[i]);

        // 기간 넘기면 제외
        if(plan[i][0] + i > N + 1) 
            continue;
        else
            dp[i + plan[i][0]] = Max(ans + plan[i][1], dp[i + plan[i][0]]);
    }

    std::cout << ans << "\n";
}