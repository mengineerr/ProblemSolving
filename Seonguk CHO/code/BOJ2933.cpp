#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
#define MAX 101
int r, c, n, h;
char map[MAX][MAX];
int visit[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1,1,0,0};

struct dat{
    int x,y;
};
struct mineral{
    vector <dat> v;
    int min = 0;
    int num;
};

mineral bfs(int x, int y, int num){
    mineral s;
    vector <dat> &v = s.v;
    queue <dat> q;
    int nx, ny;
    q.push({x,y}); v.push_back({x,y});
    visit[x][y] = num;
    s.num = num;
    while (!q.empty())
    {
        x = q.front().x; y = q.front().y; q.pop();
        s.min = (s.min < x) ? x : s.min;
        for(int i = 0; i < 4; i++){
            nx = x + dx[i]; ny = y + dy[i];
            if(0<=nx&&nx<r&&0<=ny&&ny<c){
                if(visit[nx][ny] != 0) continue;
                if(map[nx][ny] == 'x'){
                    q.push({nx,ny}); v.push_back({nx,ny}); visit[nx][ny] = num;
                }
            }
        }
    }
    return s;
}
void shoot(int dir){
    switch (dir)
    {
    case 0:
        for(int i = 0; i < c; i++){
            if(map[h][i] == 'x'){
                map[h][i] = '.';
                break;
            }
        }
        break;
    case 1:
        for(int i = c-1; i >= 0; i--){
            if(map[h][i] == 'x'){
                map[h][i] = '.';
                 break;
            }
        }
    }
    return;
}
int getDist(vector <dat> v, int num){
    int x, y;
    int dist = 100000; int val = 0;
    for(int i = 0; i < v.size(); i++){
        x = v[i].x; y = v[i].y;
        if(visit[x+1][y] == num) continue;
        val = 0;
        while (true)
        {
            x++; val++;
            if(map[x][y] == 'x' || x == r) break;
        }
        dist = (val < dist) ? val : dist;
    }
    return dist-1;
}
void update(mineral s){
    int dist;
    vector <dat> &v = s.v;
    for(int i = 0; i < v.size(); i++){
        map[v[i].x][v[i].y] = '.';
    }
    dist = getDist(s.v,s.num);
    for(int i = 0; i < v.size(); i++){
        map[v[i].x+dist][v[i].y] = 'x';
    }
}
void solve(){
    memset(visit, 0, sizeof(visit));
    int num = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(map[i][j] == 'x' && visit[i][j] == 0){
                num++;
                mineral s = bfs(i,j, num);
                if(s.min != r-1){
                    update(s);
                    return;
                }
            }
        }
    }
    return;
}
void printMap(){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
}
int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++) cin >> map[i][j]; 
    }


    cin >> n;
    int dir = 1; // 0 - 왼 1 - 오
    while(n != 0){
        n--;
        cin >> h;
        h = r - h;
        dir = (dir == 0) ? 1 : 0;
        shoot(dir);
        cout << endl;
        printMap();
        solve();
        cout << endl;
        printMap();    
    }
    printMap();

    return 0;
}