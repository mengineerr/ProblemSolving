#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int loc[101][101];
struct dat{
    int cx, cy;
    int speed, dir, size;
    int nx, ny;
    int alive = 1;
};
struct dat2{
    int x, y, dir;
};
int r, c, s, d, z; // d - 위 아래 오 왼
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
dat shark[10001];
int n, m, num;
int rest;
int ans = 0;
void printMap(){
    cout << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << loc[i][j] << " ";
        }
        cout << endl;
    }
}
void fishing(int y){
    int x = 0;
    while (true){
        if(x >= n) break;
        if(loc[x][y] != 0){
            // 물고기 잡음
            int which = loc[x][y];
            ans += shark[which].size;
            shark[which].alive = -1;
            loc[x][y] = 0;
            rest--;
            break;
        }
        x++;
    }
}
dat2 update(int x, int y, int speed, int dir){
    dat2 s;
    int nx, ny;
    while (speed != 0){
        nx = x + dx[dir]; ny = y + dy[dir];
        if(nx<0 || nx>=n || ny<0||ny>=m){
            if(dir == 0 || dir == 1){
                dir = (dir == 0) ? 1 : 0;
            }else{
                dir = (dir == 2) ? 3 : 2;
            }
            nx = x + dx[dir]; ny = y + dy[dir];
            x = nx; y = ny;
        }else{
            x = nx; y = ny;
        }
        speed--;
    }
    s.x = x; s.y = y; s.dir = dir;
    return s; 
}
void sharkMoving(){
    for(int i = 1; i < num+1; i++){
        if(shark[i].alive == -1) continue;
        dat2 next = update(shark[i].cx, shark[i].cy, shark[i].speed, shark[i].dir);
        shark[i].nx = next.x; shark[i].ny= next.y; shark[i].dir = next.dir;
        loc[shark[i].cx][shark[i].cy] = 0;
    }   // 상어 이동 먼저
    for(int i = 1; i < num+1; i++){
        if(shark[i].alive == -1) continue;
        if(loc[shark[i].nx][shark[i].ny] == 0){
            loc[shark[i].nx][shark[i].ny] = i;
            shark[i].cx = shark[i].nx; shark[i].cy = shark[i].ny;
        }else{
            int other = loc[shark[i].nx][shark[i].ny];
            if(shark[other].size > shark[i].size){
                shark[i].alive = -1;
            }else{
                shark[other].alive = -1;
                loc[shark[i].nx][shark[i].ny] = i;
                shark[i].cx = shark[i].nx; shark[i].cy = shark[i].ny;
            }
        }
    }
}
int main(){
    cin >> n >> m >> num;
    rest = num;
    memset(loc, 0, sizeof(loc));
    for(int i = 1; i < num+1; i++){
        cin >> r >> c >> s >> d >> z;
        if(d == 1 || d == 2){
            int cut = (n-1) * 2;
            s %= cut;
        }else{
            int cut = (m-1) * 2;
            s %= cut;
        }
        loc[r-1][c-1] = i; 
        shark[i].cx = r-1; shark[i].cy = c-1; shark[i].speed = s; shark[i].dir = d-1; shark[i].size = z;
    }
    for(int i = 0; i < m; i++){
        if(rest == 0) break;
        fishing(i);
        sharkMoving();
    }
    cout << ans;
    return 0;
}