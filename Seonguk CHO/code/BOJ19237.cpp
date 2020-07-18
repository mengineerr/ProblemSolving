#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 21
int n,m,k;
int map[MAX][MAX][3]; // 0 - 위치, 1 - 냄새 주인, 2 - 잔여 시간
vector <int> priorDir[MAX*MAX][4];

struct dat{
    int cx, cy, nx, ny, dir, live;
};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int ans = 0; int cnt = 0;
int total;
/*
void printMap(){
    cout << endl << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << map[i][j][0] << " ";
        }
        cout << endl;
    }
}
*/
void setTrace(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j][0] == 0) continue;
            map[i][j][1] = map[i][j][0];
            map[i][j][2] = k;
        }
    }
}
bool chk(int x, int y){
    int nx, ny;
    for(int i = 0; i < 4; i++){
        nx = x + dx[i]; ny = y + dy[i];
        if(0<=nx&&nx<n&&0<=ny&&ny<n){
            if(map[nx][ny][1] == 0){
                return true;
            }
        }
    }
    return false;
}
void move(dat s[MAX*MAX]){
    for(int i = 1; i < m+1; i++){
        dat &a = s[i];
        if(a.live == 1){
            if(chk(a.cx,a.cy)){
                // 주변 냄새 없는 것 체크
                vector <int> &idx = priorDir[i][a.dir];
                int nx, ny;
                for(int j = 0; j < 4; j++){
                    nx = a.cx + dx[idx[j]]; ny = a.cy + dy[idx[j]];
                    if(0<=nx&&nx<n&&0<=ny&&ny<n){
                        if(map[nx][ny][1] == 0){
                            a.nx = nx; a.ny = ny; a.dir = idx[j];
                            break;
                        }
                    }
                }
            }else{
                // 주변 없는 곳 X
                vector <int> &idx = priorDir[i][a.dir];
                int nx, ny;
                for(int j = 0; j < 4; j++){
                    nx = a.cx + dx[idx[j]]; ny = a.cy + dy[idx[j]];
                    if(0<=nx&&nx<n&&0<=ny&&ny<n){
                        if(map[nx][ny][1] == i){
                            a.nx = nx; a.ny = ny; a.dir = idx[j];
                            break;
                        }
                    }
                }
            }
        }
    }
    // Update
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            map[i][j][0] = 0;
        }
    } 
    for(int i = 1; i < m+1; i++){
        dat &a = s[i];
        if(a.live == 0) continue;
        if(map[a.nx][a.ny][0] != 0){
            a.live = 0; total--;  // i가 순차적으로 증가하며 탐색
        }else{
            map[a.nx][a.ny][0] = i;
            a.cx = a.nx; a.cy = a.ny;
        }
    }
}
void updateTrace(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j][1] == 0) continue;
            map[i][j][2]--;
            if(map[i][j][2] == 0) map[i][j][1] = 0;
        }
    }
}
int main(){

    // 맨 처음 모든 상어가 자신의 위치에 자신의 냄새를 뿌림
    // 1 초마다 모든 상어가 인접한 칸으로 이동, 자신의 냄새를 뿌림, 냄새는 k번 이동 후 사라짐
    // 이동 방향은 
    // 1. 아무 냄새 없는 칸을 우선순위에 따라 2. 자신의 냄새인 칸의 우선순위 따라
    // 이동 후 한칸에 여러 마리의 상어가 남아 있으면, 가장 작은 번호를 가진 상어를 제외 쫓겨남
   cin >> n >> m >> k;
   struct dat dat[MAX*MAX];
   memset(map,0,sizeof(map));
   for(int i = 0; i < n; i++){
       for(int j = 0; j < n; j++){
           cin >> map[i][j][0];
           if(map[i][j][0] != 0){
               dat[map[i][j][0]].cx = i;
               dat[map[i][j][0]].cy = j;
               dat[map[i][j][0]].live = 1;
           }
       }
   }
   for(int i = 1; i < m+1; i++){
       int temp;
       cin >> temp;
       dat[i].dir = temp - 1;
   }
   int d1,d2,d3,d4;
   for(int i = 1; i < m+1; i++){
       for(int j = 0; j < 4; j++){
           cin >> d1 >> d2 >> d3 >> d4;
           d1--;d2--;d3--;d4--;
           priorDir[i][j].push_back(d1);
           priorDir[i][j].push_back(d2);
           priorDir[i][j].push_back(d3);
           priorDir[i][j].push_back(d4);
       }
   }
   total = m;

   while(true){
       if(cnt > 1000){
           ans = -1; break;
       }
       if(total == 1){
           ans = cnt; break;
       }
       cnt++;
       setTrace();
       move(dat);
       updateTrace();
   }
   cout << ans;
   return 0;
}