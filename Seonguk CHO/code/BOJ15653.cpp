#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
char map[11][11];
int chk[11][11][2];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
// 왼 오 상 하
int endx, endy;
int ans = 0;
struct dat{
    int redx, redy, bluex, bluey;
    int dist = 0;
};
struct coord{
    int x, y;
};
queue <dat> q;
coord moving(int x, int y, int d){
    int nx, ny;
    while (true){
        nx = x + dx[d]; ny = y + dy[d];
        if(map[nx][ny] == '#') break;
        if(map[nx][ny] == 'O'){
            x = nx; y = ny;
            break;
        }
        x = nx; y = ny;
    }
    coord s;
    s.x = x; s.y = y;
    return s;
}
bool bfs(int a, int b, int c, int d){
    int redx, redy, bluex, bluey;
    int dist;
    chk[a][b][0] = 1; chk[c][d][1] = 1;
    q.push({a,b,c,d,0});
    while (!q.empty()){
        redx = q.front().redx; redy = q.front().redy; bluex = q.front().bluex; bluey= q.front().bluey;
        dist = q.front().dist;
        q.pop();
        for(int i = 0; i < 4; i++){
            coord redNext = moving(redx, redy, i);
            coord blueNext = moving(bluex, bluey, i);
            
            if(endx == blueNext.x && endy == blueNext.y) continue;
            if(endx == redNext.x && endy == redNext.y){
                ans = dist + 1;  // 종료 조건
                return true;
            }
            if(redNext.x == blueNext.x && redNext.y == blueNext.y){
                // 두개 겹치는 경우
                if(i==0){
                    if(redy>bluey) redNext.y++;
                    else blueNext.y++;
                }else if(i==1){
                    if(redy>bluey) blueNext.y--;
                    else redNext.y--;
                }else if(i==2){
                    if(redx>bluex) redNext.x++;
                    else blueNext.x++;
                }else{
                    if(redx>bluex) blueNext.x--;
                    else redNext.x--;
                }
            }
            if(chk[redNext.x][redNext.y][0] == 1 && chk[blueNext.x][blueNext.y][1] == 1) continue;
            if(redx == redNext.x && redy == redNext.y && bluex == blueNext.x && bluey == blueNext.y) continue;
            chk[redNext.x][redNext.y][0] = 1; chk[blueNext.x][blueNext.y][1] = 1;
            q.push({redNext.x,redNext.y,blueNext.x,blueNext.y,dist+1});
        }
    }
    return false;
}
int main(){
    cin >> n >> m;
    int a, b, c, d;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] == 'R'){
                a = i; b = j; map[i][j] = '.';
            }
            if(map[i][j] == 'B'){
                c = i; d = j; map[i][j] = '.';
            }
            if(map[i][j] == 'O'){
                endx = i; endy = j;
            }
        }
    }
    if(bfs(a,b,c,d)){
        cout << ans;
    }else cout << -1;
    return 0;
}