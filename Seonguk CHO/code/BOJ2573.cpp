#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 301
int n,m;
int map[MAX][MAX];
int visit[MAX][MAX];
int temp[MAX][MAX];
int land = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
struct dat{
    int x, y;
};

void bfs(int cx, int cy){
    int x, y, nx, ny;
    queue <dat> q;
    q.push({cx,cy});
    visit[cx][cy] = 1;
    while(!q.empty()){
        x = q.front().x; y = q.front().y;
        q.pop();
        for(int i = 0; i < 4; i++){
            nx = x + dx[i]; ny = y + dy[i];
            if(0<=nx&&nx<n&&0<=ny&&ny<m){
                if(map[nx][ny] != 0 && visit[nx][ny] == 0){
                    q.push({nx, ny});
                    visit[nx][ny] = 1;
                }
            }
        }
    }  
    return;
}
bool solve(){
    int num = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] > 0 && visit[i][j] == 0){
            num++;
            if(num == 2) return false;
            bfs(i,j);
            }
        }
    }
    return true;
}
int val(int x, int y){
    int nx, ny;
    int cnt = 0;
    for(int i = 0; i < 4; i++){
        nx = x + dx[i]; ny = y + dy[i];
        if(nx<0||nx>=n||ny<0||ny>=m) continue;
        if(map[nx][ny] == 0) cnt++;
    }
    return cnt;
}
void change(){
    int num;
    memset(temp, 0 , sizeof(temp));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] > 0) temp[i][j] = val(i,j);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 0) continue;
            if(temp[i][j] >= map[i][j]){
                land--;
                map[i][j] = 0;
            }else{
                map[i][j] -= temp[i][j];
            }
        }
    }
}
int main(){
    cin >> n >> m;
    memset(map, 0,sizeof(map));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] > 0) land++;  
        } 
    }
    int cnt = 0;
    int num = 0;
    while (true)
    {
        memset(visit, 0, sizeof(visit));
        if(!solve()) break;
        change();
        if(land == 0){
            cnt = 0;
            break;
        }
        cnt++;
    }
    cout << cnt;
    return 0;
}
