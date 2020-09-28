#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector <vector<int>> v = {{0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40},
                          {10,13,16,19,25}, {20,22,24,25}, {30,28,27,26,25}, {25,30,35,40},
                          {40,0}};
int chk[6][22];
int step[10] = {0,};
int ans = 0;
// 0 -> 일반 루트, 1, 2, 3 파란화살표 4 합쳐지는 곳 5 마지막
struct loc{
    int x, y;
};
vector <loc> now = {{0,0},{0,0},{0,0},{0,0}};
loc mov(int x, int y, int num){
    loc s;
    int nx, ny;
    ny = y + num;
    if(x == 0 && ny%5 == 0){
        if(ny == 20){
            s.x = 5; s.y = 0;
        }else{
            s.x = ny/5; s.y = 0;
        }
    }else if(x == 0){
        if(ny >= v[0].size()-1){
            s = mov(5,0,ny - v[0].size() + 1);
        }else{
            s.x = 0; s.y = ny;
        }
    }else{
        if(1<=x && x<=3){
            if(ny >= v[x].size()-1){
                s = mov(4,0,ny-v[x].size()+1);
            }else{
                s.x = x; s.y= ny;
            }
        }else if(x == 4){
            if(ny >= v[x].size()-1) s = mov(5,0,ny-v[x].size()+1);
            else{
                s.x = x; s.y = ny;
            } 
        }else{
            if(ny > 1){
                s.x = -1; s.y = -1;
            }else{
                s.x = x; s.y = ny;
            }
        }
    }
    return s;
}
void dfs(int cnt, int num){
    if(cnt == 10){
        // 종료조건
        ans = (ans < num) ? num : ans;
        return;
    }
    int x, y, nx, ny;
    for(int i = 0; i < 4; i++){
        x = now[i].x; y = now[i].y;
        if(x == -1) continue; // 이미 도착함
        loc next = mov(x,y,step[cnt]);
        if(next.x == -1){
            // 말이 도착한 경우
            chk[x][y] = 0; now[i].x = -1; now[i].y = -1;
            dfs(cnt+1, num);
            chk[x][y] = 1; now[i].x = x; now[i].y = y;
        }else{
            // 아닌 경우
            nx = next.x; ny = next.y;
            if(nx == 5 && ny == 1){
                chk[x][y] = 0; now[i].x = nx; now[i].y = ny;
                dfs(cnt+1, num+v[nx][ny]);
                chk[x][y] = 1; now[i].x = x; now[i].y = y;
            }else if(chk[nx][ny] == 0){
                chk[nx][ny] = 1; chk[x][y] = 0; now[i].x = nx; now[i].y = ny;
                dfs(cnt+1, num+v[nx][ny]);
                chk[nx][ny] = 0; chk[x][y] = 1; now[i].x = x; now[i].y = y;
            }
        }
    }
}

int main(){
    for(int i = 0; i < 10; i++) cin >> step[i];
    memset(chk, 0, sizeof(chk));
    dfs(0,0);
    cout << ans;
    return 0;
}
