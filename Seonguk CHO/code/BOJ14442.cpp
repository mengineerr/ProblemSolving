#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define MAX 1001
int map[MAX][MAX];
int visit[MAX][MAX][11];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
struct dat{
    int x, y, en;
};
int n, m, k;
int ans = 10000000;
void solve(){
    int x, y, nx, ny, dist, en;
    queue <dat> q;
    q.push({0,0,0});
    visit[0][0][0] = 1;
    if(n-1 == 0 && m-1 == 0){
        ans = 0; return;
    }
    while (!q.empty())
    {
        x = q.front().x; y = q.front().y; en = q.front().en;
        q.pop();
        for(int i = 0; i < 4; i++){
            nx = x + dx[i]; ny = y + dy[i];
            if(0<=nx&&nx<n&&0<=ny&&ny<m){
                if(nx == n-1 && ny == m-1){
                    ans = visit[x][y][en]+1;
                    return;
                }
                if(map[nx][ny] == 1 && en < k){
                    if(visit[nx][ny][en+1] != 0) continue;
                    q.push({nx,ny,en+1});
                    visit[nx][ny][en+1] = visit[x][y][en]+1;
                }else if(map[nx][ny] == 0 && visit[nx][ny][en] == 0){
                    q.push({nx,ny,en});
                    visit[nx][ny][en] = visit[x][y][en]+1;
                }
            }
        }
        
    }
    
}
int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    memset(visit, 0, sizeof(visit));
    solve();
    if(ans == 10000000){
        cout << -1;
    }else{
        cout << ans;
    }

    return 0;
}