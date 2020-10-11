#include <iostream>
#include <queue>

using namespace std;

int n, m;
// 열쇠 a - f
char map[51][51];
bool chk[51][51][1<<6];
struct dat{
    int x, y;
    int dist;
    int key;
};
int cx, cy;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int ans = 0;
bool bfs(){
    int x, y, dist, key, nx, ny;
    queue<dat> q;
    q.push({cx,cy,0,0});
    chk[cx][cy][0] = true;
    while (!q.empty()){
        x = q.front().x; y = q.front().y; dist = q.front().dist; key = q.front().key;
        q.pop();
        for(int i = 0 ; i < 4; i++){
            nx = x + dx[i]; ny = y + dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(chk[nx][ny][key]) continue;
            if(map[nx][ny] == '#') continue;
            if(map[nx][ny] == '1'){
                // 탈출
                ans = dist + 1;
                return true;
            }
            if(map[nx][ny] == '.' ){
                chk[nx][ny][key] = true;
                q.push({nx,ny,dist+1,key});
            }else if(map[nx][ny] >= 'a' && map[nx][ny]  <= 'f'){
                int whichKey = key | (1<<(int(map[nx][ny]-'a')));
                chk[nx][ny][whichKey] = true;
                q.push({nx,ny,dist+1,whichKey});
            }else if(map[nx][ny] >= 'A' && map[nx][ny] <= 'F'){
                int door = key & (1<<(int(map[nx][ny]-'A')));
                if(door > 0){
                    chk[nx][ny][key] = true;
                    q.push({nx,ny,dist+1,key});
                }
            }
        }
    }
    return false;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] == '0'){
                cx = i; cy = j;
                map[i][j] = '.';
            }
        }
    }
    if(bfs()){
        cout << ans;
    }else cout << -1;
    return 0;
}