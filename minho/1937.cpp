#include <iostream>
#include <cstring>
#define MAX 500

using namespace std;

int forest[MAX][MAX];
int dp[MAX][MAX] = {0};
int N = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ans = 0;

struct loc{
    int y;
    int x;
    int time;
};

int dfs(int y, int x){
    if(dp[y][x])
        return dp[y][x];
    
    dp[y][x] = 1;

    for(int i = 0; i < 4; i++){
        if(y + dy[i] < 0 || y + dy[i] > N-1 || x + dx[i] < 0 || x + dx[i] > N-1) continue;
        if(forest[y][x] >= forest[y+dy[i]][x+dx[i]]) continue;

        dp[y][x] = max(dp[y][x], dfs(y+dy[i],x+dx[i]) + 1);
    }

    return dp[y][x];
}

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> forest[i][j];
    
    for(int i = 0; i < N; i++){
        for(int j = 0;j < N; j++){
            ans = max(ans, dfs(i,j));
        }
    }

    cout << ans << "\n";

    return 0;
}