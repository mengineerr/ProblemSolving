#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define MAX 51

int t;
int m, n, k;
int map[MAX][MAX];
int visit[MAX][MAX];
int dx[4] = {0, 0, -1, 1}; int dy[4] = {1, -1, 0,0};
vector <int> ans;
struct dat{
    int x, y;
};

void solve(int i, int j){
    int x, y, nx, ny;
    queue <dat> q;
    q.push({i,j});
    visit[i][j] = 1;
    while(!q.empty()){
        x = q.front().x; y = q.front().y;
        q.pop();
        for(int i = 0; i < 4; i++){
            nx = x + dx[i]; ny = y + dy[i];
            if(0<=nx&&nx<n&&0<=ny&&ny<m){
                if(map[nx][ny] == 1 && visit[nx][ny] == 0){
                    q.push({nx,ny});
                    visit[nx][ny] = 1;
                }
            }
        }
    }
    return;
}
int main(){
    cin >> t;
    while(t!=0){
        cin >> m >> n >> k;
        int cnt = 0;
        memset(map,0,sizeof(map));
        memset(visit,0,sizeof(visit));
        for(int i = 0; i < k; i++){
            int x, y;
            cin >> y >> x;
            map[x][y] = 1;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(map[i][j] == 1 && visit[i][j] == 0){
                    cnt++;
                    solve(i,j);
                }
            }
        }
        ans.push_back(cnt);
        t--;
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}