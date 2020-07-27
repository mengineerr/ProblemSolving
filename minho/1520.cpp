#include <iostream>

using namespace std;

int **map;
int **dp;
int N, M;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int sol(int i, int j){
    if(i == N-1 && j == M-1){
        return 1;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int curx,cury = 0;
    dp[i][j] = 0;

    for(int k = 0; k < 4; k++){
        curx = j + dx[k];
        cury = i + dy[k];
        if(curx < 0 || curx > M-1 || cury < 0 || cury > N-1)
            continue;
        if(map[i][j] > map[cury][curx])
            dp[i][j] += sol(cury,curx);
    }

    return dp[i][j];
}

int main()
{
    
    cin >> N >> M;
    map = new int*[N];
    dp = new int*[N];
    for(int i = 0; i < N; i++){
        map[i] = new int[M];
        dp[i] = new int[M];
    }
        
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            dp[i][j] = -1;
        }

    cout << sol(0,0) << "\n";

    return 0;
}