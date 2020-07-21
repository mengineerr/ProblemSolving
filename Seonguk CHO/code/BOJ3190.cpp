#include <iostream>
#include <vector>
#include <cstring>
#include <deque>

using namespace std;
#define MAX 101

int dir = 0;  
// 방향 오 아 왼 위
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct snake{
    int x, y;
};
struct dirSet{
    int t;
    char dir;
};
vector <dirSet> v;
deque <snake> q;
int map[MAX][MAX];
int n, k, l;

void printMap(){
    cout << endl;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}
bool move(){
    int nx, ny;
    int x = q.front().x; int y = q.front().y;
    nx = x + dx[dir]; ny = y + dy[dir];
    if(nx<0 || nx >= n || ny<0 || ny>=n || map[nx][ny] == 1) return false;
    q.push_front({nx,ny}); 
    if(map[nx][ny] == 0){
        // 사과 못먹
        int tx = q.back().x; int ty = q.back().y;
        q.pop_back(); map[tx][ty] = 0;
        map[nx][ny] = 1;
    }else if(map[nx][ny] == 2){
        // 사과 먹
        map[nx][ny] = 1;
    }
    return true;
}
void change(){
    for(int i = 0; i < v.size(); i++){
        if(v[i].t == -1) continue;
        v[i].t--;
        if(v[i].t == 0){
            v[i].t = -1;
            if(v[i].dir == 'D'){
                dir += 1;
                if(dir == 4) dir = 0;
            }else{
                dir -= 1;
                if(dir == -1) dir = 3;
            }
        }
    }
    return;
}
int main(){
    cin >> n >> k;
    memset(map, 0, sizeof(map));
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        map[a-1][b-1] = 2; 
    }
    cin >> l;
    for(int i = 0; i < l ; i++){
        int a; char b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    map[0][0] = 1;
    q.push_front({0,0});
    int cnt = 0;
    while (true)
    {
        cnt++;
        printMap();
        if(!move()) break;
        change();
    }
    
    cout << cnt;

    return 0;
}