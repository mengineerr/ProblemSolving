#include <iostream>

using namespace std;

struct fish{
    int x, y, dir, alive;
};

int map[4][4];
fish f[17];
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};
int ans = 0;
void copyAll(int copyMap[4][4], fish c[17]){
    int idx = 1;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            copyMap[i][j] = map[i][j];
            c[idx] = f[idx]; idx++;
        }
    }
}
void restore(int copyMap[4][4], fish c[17]){
    int idx = 1;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            map[i][j] = copyMap[i][j];
            f[idx] = c[idx]; idx++;
        }
    }
}
void move(int sx, int sy){
    int nx, ny, dir;
    int who;
    for(int i = 1; i < 17; i++){
        fish &a = f[i];
        if(a.alive == 0) continue;
        for(int j = 0; j < 8; j++){
            dir = (a.dir + j) % 8;
            nx = a.x + dx[dir]; ny = a.y + dy[dir];
            if(nx<0||nx>=4||ny<0||ny>=4) continue;
            if(nx == sx && ny == sy) continue; // 상어 위치
            if(map[nx][ny] == 0){
                // 빈공간
                map[a.x][a.y] = 0; map[nx][ny] = i;
                a.x = nx; a.y = ny; a.dir = dir;
                break;
            }else{
                // 다른 물고기
                who = map[nx][ny];
                fish &b = f[who];
                map[a.x][a.y] = who;
                b.x = a.x; b.y = a.y; 
                a.x = nx; a.y = ny; a.dir = dir;
                map[nx][ny] = i;
                break;
            }
        }
    }
}
void solve(int x, int y, int val){
    int nx, ny, cx, cy, sdir;
    int who;
    int copyMap[4][4];
    fish c[17];
    copyAll(copyMap, c);
    ans = (ans<val)? val : ans;
    who = map[x][y]; // 상어가 먹을 놈
    sdir = f[who].dir; f[who].alive = 0;
    map[x][y] = 0;  // 빈칸 설정
    move(x,y);      // 물고기 이동
    // 다음 상어이동
    nx = x; ny = y;
    while (true){
        nx += dx[sdir]; ny += dy[sdir];
        if(nx<0||nx>=4||ny<0||ny>=4) break;
        if(map[nx][ny] == 0) continue;
        solve(nx,ny,val + map[nx][ny]);
    }
    restore(copyMap, c);
}
int main(){
    // 재귀 방식으로 모든 경우 탐색
    // 상어가 물고기를 이동하여 먼저 먹는다.
    // 물고기가 이동한다.
    // 그 다음 상어가 먹은 물고기 방향을 따라 다시 움직인다. 
    int a, b;
    for(int i=0; i < 4; i++){
        for(int j =0; j < 4; j++){
            cin >> a >> b;
            map[i][j] = a;
            f[a].x = i; f[a].y = j; f[a].dir = b-1; f[a].alive = 1;
        }
    }
    solve(0,0,map[0][0]);
    cout << ans;
    return 0;
}