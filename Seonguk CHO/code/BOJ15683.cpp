#include <iostream>
#include <vector>

using namespace std;

#define MAX 10

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n,m;
int map[MAX][MAX];
struct camera{
    int x, y, type;
};
struct Dir{
    vector <int> dir;
};
vector <camera> v;
int ans = 1000000;
int cal(){
    int temp = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 0) temp++;
        }
    }
    return temp;
}
void search(int x, int y, int dir){
    int nx, ny;
    dir %= 4;
    while (true)
    {
        nx = x + dx[dir]; ny = y + dy[dir];
        if(nx<0 || nx >= n || ny<0 || ny>=m) break;
        if(map[nx][ny] == 6) break;
        if(0<map[nx][ny] && map[nx][ny] < 6){
            x = nx; y = ny;
        }else{
           map[nx][ny] = -1;
           x = nx; y = ny;
        }
    }
    return;    
}
void mapCopy(int copyMap[MAX][MAX]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) copyMap[i][j] = map[i][j];
    }
}
void restore(int copyMap[MAX][MAX]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) map[i][j] = copyMap[i][j];
    }
}
void solve(int idx){

    if(idx == v.size()){
        // 재귀 종료 조건
        int result;
        result = cal();
        ans = (result < ans) ? result : ans;
        return;
    }
    int x, y, type;
    x = v[idx].x; y = v[idx].y; type = v[idx].type;
    int rotNum[6] = {0, 4, 2, 4, 4, 1}; 
    int copyMap[MAX][MAX];
    mapCopy(copyMap);
    for(int i = 0; i < rotNum[type]; i++){
        switch (type)
        {
        case 1:
            search(x,y,i);
            break;
        case 2:
            search(x,y,i);
            search(x,y,i+2);
            break;
        case 3:
            search(x,y,i);
            search(x,y,i+1);
            break;
        case 4:
            search(x,y,i);
            search(x,y,i+1);
            search(x,y,i+2);
            break;
        case 5:
            search(x,y,i);
            search(x,y,i+1);
            search(x,y,i+2);
            search(x,y,i+3);
            break;
        default:
            break;
        }
        solve(idx+1);
        restore(copyMap);
    }


}
int main(){
    // CCTV 종류는 5 가지
    // 방향 설정 오른 아래 왼쪽 위
    // 방향에 따른 Vector 데이터 접근하여 루프로 탐색 시작?
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(0< map[i][j] && map[i][j] < 6){
                v.push_back({i,j,map[i][j]});
            }
        }
    }
    solve(0);

    cout << ans;
    return 0;
}