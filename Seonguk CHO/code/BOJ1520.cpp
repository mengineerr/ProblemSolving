#include <iostream>
#include <cstring>
using namespace std;

#define MAX 501
int map[MAX][MAX];
int dp[MAX][MAX];
int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int sol(int x, int y){
    if(dp[x][y] != -1) return dp[x][y]; // 이미 방문
    if(x == n -1 && y == m -1){
        return 1; // dp 값 업데이트
    }
    int nx, ny;
    dp[x][y] = 0;
    for(int i = 0; i < 4; i++){
        nx = x + dx[i]; ny = y + dy[i];
        if(0<=nx&&nx<n&&0<=ny&&ny<m){
            if(map[x][y] > map[nx][ny]){
                dp[x][y] += sol(nx,ny);
            }
        }
    }
    return dp[x][y];
}
int main(){
    cin >> n >> m;
    for(int i = 0; i<n;i++){
        for(int j = 0; j<m;j++) cin >> map[i][j];
    }
    memset(dp, -1, sizeof(dp));
    cout << sol(0,0);
    return 0;
}