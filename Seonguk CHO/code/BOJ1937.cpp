#include <iostream>
#include <cstring>

using namespace std;

#define MAX 501
int n;
int map[MAX][MAX];
int visit[MAX][MAX];
int ans = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int solve(int x, int y){
    int nx, ny;
    if(visit[x][y] != -1) return visit[x][y];
    visit[x][y] = 1;
    for(int i = 0; i < 4; i++){
        nx = x + dx[i]; ny = y + dy[i];
        if(0<=nx&&nx<n&&0<=ny&&ny<n){
            if(map[x][y] >= map[nx][ny]) continue;
            visit[x][y] = max(visit[x][y],solve(nx,ny)+1);
        }
    }
    return visit[x][y];
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> map[i][j];
    }
    memset(visit, -1, sizeof(visit));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans = max(ans,solve(i,j));
        }
    }
    cout << ans;
    return 0;
}