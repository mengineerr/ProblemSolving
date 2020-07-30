#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 101

int n,m;
int map[MAX][MAX];
int visit[MAX][MAX];

struct dat{
    int x, y;
};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int num = 0;
int ans = 0;
void printMap(){
    cout << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}
void bfs(){
    int x,y,nx,ny;
    memset(visit,0,sizeof(visit));
    queue <dat> q;
    q.push({0,0});  
    visit[0][0] = 1;

    while(!q.empty()){
        x = q.front().x; y = q.front().y;
        q.pop();
        for(int i = 0; i < 4; i++){
            nx = x + dx[i]; ny = y + dy[i];
            if(0<=nx&&nx<n&&0<=ny&&ny<m){
                if(visit[nx][ny] == 1) continue;
                if(map[nx][ny] == 0){
                    q.push({nx,ny});
                    visit[nx][ny] = 1;
                }
            }
        }
    }
    return;
}
int chk(int x, int y){
    int nx, ny;
    int cnt = 0;
    for(int i = 0; i < 4; i++){
        nx = x + dx[i]; ny = y + dy[i];
        if(visit[nx][ny] == 1) cnt++;
    }
    return cnt;
}
void change(){
    int temp;
    vector <dat> v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 1){
                temp = chk(i,j);
                if(temp >=2) v.push_back({i,j});
            }
        }
    }
    for(int i = 0; i < v.size(); i++){
        map[v[i].x][v[i].y] = 0; num--;
    }
}
int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) num++;
        }
    }

    while (true)
    {
        if(num == 0) break;
        ans++;
        bfs();
        change();
    }
    cout << ans;
    return 0;
}