#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 26

int n;
int map[MAX][MAX];
int visit[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1,1, 0,0};
vector <int> ans;
struct dat{
    int x,y;
};
void solve(int cx, int cy){
    int x,y,nx,ny;
    int cnt = 0;
    queue<dat> q;
    q.push({cx,cy});
    visit[cx][cy] = 1;
    while(!q.empty()){
        x = q.front().x; y = q.front().y;
        visit[x][y] = 1;
        q.pop();
        cnt++;
        for(int i = 0 ; i < 4; i++){
            nx = x + dx[i]; ny = y + dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<n){
                if(map[nx][ny] == 1 && visit[nx][ny] == 0){
                    q.push({nx,ny});
                    visit[nx][ny] = 1;
                }
            }
        }
    }
    ans.push_back(cnt);
    return;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j<n;j++){
            scanf("%1d", &map[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == 1 && visit[i][j] == 0){
                solve(i,j);
            }
        }
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }


    return 0;
}
