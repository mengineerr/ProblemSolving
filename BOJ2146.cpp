#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define MAX 101
int n;
int map[MAX][MAX];
int visit[MAX][MAX];
int island[MAX][MAX];
struct dat{
    int x, y;
};
struct dat1{
    int x, y, dist;
};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int ans = 100000;

void setNum(int x, int y, int num){
    int nx, ny;
    memset(visit,0,sizeof(visit));
    queue <dat> q;
    q.push({x,y});
    visit[x][y] = 1;
    island[x][y] = num;
    while(!q.empty()){
        x = q.front().x; y = q.front().y;
        q.pop();
        for(int i = 0; i < 4; i++){
            nx = x + dx[i]; ny = y + dy[i];
            if(0<=nx&&nx<n&&0<=ny&&ny<n){
                if(visit[nx][ny] == 1) continue;
                if(map[nx][ny] == 1 && island[nx][ny] == 0){
                    island[nx][ny] = num;
                    visit[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
    }
}

void getDist(int x, int y, int num){
    int nx, ny, dist;
    memset(visit,0,sizeof(visit));
    queue <dat1> q;
    q.push({x,y,0});
    visit[x][y] = 1;
    while(!q.empty()){
        x = q.front().x; y = q.front().y; dist = q.front().dist;
        if(dist > ans) return;
        q.pop();
        for(int i = 0; i < 4; i++){
            nx = x + dx[i]; ny = y + dy[i];
            if(0<=nx&&nx<n&&0<=ny&&ny<n){
                if(visit[nx][ny] != 0 || island[nx][ny] == num) continue;
                if(island[nx][ny] == 0){
                    q.push({nx,ny,dist+1});
                    visit[nx][ny] = 1;
                }else if(island[nx][ny] != num){
                    ans = (dist < ans) ? dist : ans;
                    return;
                }
            }
        }
    }
}
bool chk(int x, int y){
    int nx, ny;
    for(int i = 0; i < 4; i++){
        nx = x + dx[i]; ny = y + dy[i];
        if(0<=nx&&nx<n&&0<=ny&&ny<n){
            if(island[nx][ny] == 0) return true;
        }
    }
    return false;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> map[i][j];
    }
    int islandNum = 1;
    memset(island,0,sizeof(island));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == 1 && island[i][j] == 0){
                setNum(i,j,islandNum); islandNum++;
            }
        }
    }
    int temp = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(island[i][j] == 0) continue;
            if(chk(i,j)){
                getDist(i,j,island[i][j]);
            }
        }
    }
    cout << ans;
    return 0;
}