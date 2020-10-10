#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

struct cord{
    int x, y;
};
struct dat{
    int x, y, color;
};
vector <cord> avail;
vector <int> ord;

int map[51][51];
int chk[51][51];
int colorMap[51][51][2];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n, m, g, r;
int ans =0;
int cnt;
int availSize = 0;

vector <dat> bfs(vector<dat> v, int t){
    vector <dat> result;
    vector <dat> final;
    int x, y, color, nx, ny;
    for(auto a : v){
        x = a.x; y = a.y; color = a.color;
        for(int i = 0; i < 4; i++){
            nx = x + dx[i]; ny = y + dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(map[nx][ny] == 0) continue;
            if(chk[nx][ny] == 0){
                chk[nx][ny] = color; colorMap[nx][ny][color-1] = t;
                result.push_back({nx,ny,color});
            }else if(chk[nx][ny] != 0){
                if(chk[nx][ny] == 3 || chk[nx][ny] == color) continue;
                if(colorMap[nx][ny][0] == t || colorMap[nx][ny][1] == t){
                    chk[nx][ny] = 3; cnt++;
                }
            }
        }
    }
    for(auto a : result){
        if(chk[a.x][a.y] == 3) continue;
        final.push_back({a.x,a.y,chk[a.x][a.y]});
    }
    return final;
}
vector <dat> a;
void select(int idx, int gcnt, int rcnt){
    if(gcnt + rcnt > (availSize-idx)) return;
    if(gcnt == 0 && rcnt == 0){
        cnt = 0; int t = 1;
        memset(chk, 0, sizeof(chk));
        memset(colorMap, -1, sizeof(colorMap));
        for(auto sel : a){
            colorMap[sel.x][sel.y][sel.color-1] = t -1;
            chk[sel.x][sel.y] = sel.color;
        }
        vector <dat> v = a;
        while (!v.empty()){
            v = bfs(v,t);
            t++;
        }
        ans = (ans < cnt) ? cnt : ans;
        return;
    }
    if(idx == availSize) return;
    int x = avail[idx].x;
    int y = avail[idx].y;
    select(idx+1, gcnt, rcnt);
    if(gcnt>0){
        a.push_back({x,y,1});
        select(idx+1, gcnt-1, rcnt);
        a.pop_back();
    }
    if(rcnt>0){
        a.push_back({x,y,2});
        select(idx+1, gcnt, rcnt-1);
        a.pop_back();
    }
}

int main(){
    cin >> n >> m >> g >> r;
    memset(map, 0, sizeof(map));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // 0 호수, 1 뿌릴 수 없는 땅, 2 뿌릴 수 있는 땅
            cin >> map[i][j];
            if(map[i][j] == 2){
                avail.push_back({i,j});
            }
        }
    }
    availSize = avail.size();
    select(0,g,r);
    cout << ans;
    return 0;
}