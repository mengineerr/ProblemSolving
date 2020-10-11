#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};  
int n, k;

struct dat{
    int x, y, dir;
};
int map[14][14] = {0,};    // 0 - 흰색, 1 - 빨강, 2 - 파랑
vector <int> loc[14][14];  // 가장 아래에 있는 말만 이동 가능
vector <dat> stat;

bool play(){
    int x, y, nx,ny,dir;
    for(int i = 0; i < k; i++){
        x = stat[i].x; y = stat[i].y; dir = stat[i].dir;
        vector <int> &v = loc[x][y];
        if(v.front() == i){
            nx = x + dx[dir]; ny = y + dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=n){
                if(dir==0||dir==1) dir = (dir==0) ? 1 : 0;
                else dir = (dir==2) ? 3 : 2;
                nx = x + dx[dir]; ny = y + dy[dir]; stat[i].dir = dir;
            }else if(map[nx][ny] == 2){
                if(dir==0||dir==1) dir = (dir==0) ? 1 : 0;
                else dir = (dir==2) ? 3 : 2;
                nx = x + dx[dir]; ny = y + dy[dir]; stat[i].dir = dir;                
            }
            if(0<=nx&&nx<n&&0<=ny&&ny<n){
                if(map[nx][ny] == 2) continue;
                if(map[nx][ny] == 0){
                    for(int num : v){
                        loc[nx][ny].push_back(num);
                        stat[num].x = nx; stat[num].y = ny;
                    }
                    v.clear();
                }else if(map[nx][ny] == 1){
                    while (!v.empty()){
                        int num = v.back();
                        loc[nx][ny].push_back(num);
                        stat[num].x = nx; stat[num].y = ny;
                        v.pop_back();
                    }
                }
                if(loc[nx][ny].size() >= 4) return true;
            }
        }
    }
    return false;
}
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> map[i][j];
    }
    int r, c, dir;
    for(int i = 0; i < k; i++){
        cin >> r >> c >> dir;
        stat.push_back({r-1,c-1,dir-1});
        loc[r-1][c-1].push_back(i);
    }
    // 종료 조건- 턴이 진행되던 중 말이 4개 이상 쌓이는 순간.
    // 1000보다 크면 -1 출력
    int cnt = 1;
    while(true){
        if(cnt > 1000){
            cnt = -1; break;
        }
        // 드론 이동
        if(play()) break;
        cnt++;
    }
    cout << cnt;
    return 0;
}