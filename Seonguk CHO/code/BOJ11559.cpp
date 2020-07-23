#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int map[12][6];
int visit[12][6];
int crush[12][6];

struct dat{
    int x, y;
};
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

vector <dat> bfs(int cx, int cy, int val){
    vector <dat> v;
    int x,y,nx, ny;
    queue <dat> q;
    q.push({cx,cy});
    v.push_back({cx,cy});
    visit[cx][cy] = 1;
    while (!q.empty()){
        x = q.front().x; y = q.front().y;
        q.pop();
        for(int i =0 ; i < 4; i++){
            nx = x + dx[i]; ny = y + dy[i];
            if(0<=nx && nx<12 && 0<=ny && ny<6){
                if(visit[nx][ny] == 1) continue;
                if(map[nx][ny] == val){
                    q.push({nx,ny});
                    visit[nx][ny] = 1;
                    v.push_back({nx,ny});
                }
            }
        }
    }
    return v;
}
void update(){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            if(crush[i][j] == 1) map[i][j] = 0;
        }
    }   // 블럭 지우기
    int x,y,nx,ny;
    for(int i = 11; i >= 0; i--){
        for(int j = 0; j < 6; j++){
            if(map[i][j] != 0){
                x = i;
                while (true)
                {
                    nx = x + 1;
                    if(nx == 12 || map[nx][j] != 0) break;
                    map[nx][j] = map[x][j];
                    map[x][j] = 0;
                    x = nx;
                }
                
            }
        }
    }
}
int main(){
    char a;
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            //scanf("%1c", &a);
            cin >> a;
            switch (a)
            {
            case '.':
                map[i][j] = 0; break;
            case 'R':
                map[i][j] = 1; break;
            case 'G':
                map[i][j] = 2; break;
            case 'B':
                map[i][j] = 3; break;
            case 'P':
                map[i][j] = 4; break;
            case 'Y':  
                map[i][j] = 5; break;
            }
        }
    }

    int cnt = 0;
    bool flag = false;
    while (true)
    {
        memset(visit, 0, sizeof(visit));
        memset(crush, 0, sizeof(crush));
        flag = false;
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 6; j++){
                if(map[i][j] >= 1 && visit[i][j] == 0){
                    vector <dat> v = bfs(i,j,map[i][j]);
                    if(v.size() >= 4){
                        flag = true;
                        for(int k = 0; k < v.size(); k++){
                            crush[v[k].x][v[k].y] = 1;
                        }
                    }
                }
            }
        }
        if(!flag) break;
        // Update
        update();
        cnt++;
    }
    cout << cnt;
    return 0;
}