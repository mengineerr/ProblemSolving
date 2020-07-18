#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 21

int n,m,f;
int map[MAX][MAX];
int visit[MAX][MAX];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int total;
struct custom{
    int x,y,tox,toy;
};
struct dat{
    int x, y, dist;
};
struct cmp{
    bool operator()(dat a, dat b){
        if(a.dist == b.dist){
            if(a.x == b.x) return a.y > b.y;
            return a.x > b.x;
        }
        return a.dist > b.dist;
    }
};
struct taxi{
    int x, y, fuel, dist1, dist2, who;
};

void bfs(int cx, int cy){
    int x,y,nx,ny;
    queue <pair<int,int>> q;
    visit[cx][cy] = 1;
    q.push({cx,cy});
    while(!q.empty()){
        x = q.front().first; y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            nx = x + dx[i]; ny = y + dy[i];
            if(0<=nx&&nx<n&&0<=ny&&ny<n){
                if(map[nx][ny] == -1) continue;
                if(visit[nx][ny] != 0) continue;
                if(map[nx][ny] >= 0){
                    visit[nx][ny] = visit[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }
}
vector <custom> v;

int main(){

    // M 명 승객 태움. 항상 최단 경로 이동
    // 출발지에서만 택시를 타고 목적지에서만 내림
    // 승객은 현재 위치에서 최단거리 짦음, 중복 경우 행이 작은 -> 열이 적은
    // 탐색 순서 위 왼 오 아래
    // 연료는 한칸 이동시 1씩 소모, 목적지로 이동하면 소모한 연료 양의 두배 충전, 이동 중 연료 바닥 실패
    // 최종적으로 남는 연료의 양 출력
    cin >> n >> m >> f;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) map[i][j] = -1;
        }
    }
    int a, b,c,d;
    cin >> a >> b;
    taxi t;
    t.x = a-1; t.y = b-1; t.fuel = f; t.dist1 = 0; t.dist2 = 0; t.who = 0;
    v.push_back({0,0,0,0});
    for(int i = 1; i < m+1; i++){
        cin >> a >> b >> c >> d;
        map[a-1][b-1] = i;
        v.push_back({a-1,b-1,c-1,d-1});
    }
    total = m;
    int ans = 0;
    while(total != 0){
        memset(visit,0,sizeof(visit));
        bfs(t.x, t.y);
        priority_queue<dat, vector<dat>, cmp> pq;
        for(int i = 0; i<n;i++){
            for(int j =0; j<n; j++){
                if(visit[i][j] > 0 && map[i][j] >=1) pq.push({i,j,visit[i][j]-1});
            }
        }
        if(pq.size() == 0){
            ans = -1; break;
        }else{
            t.x = pq.top().x; t.y = pq.top().y; t.dist1 = pq.top().dist; t.who = map[t.x][t.y];
        }
        while(!pq.empty()) pq.pop();
        if(t.fuel < t.dist1){
            ans = -1; break;
        }
        memset(visit,0,sizeof(visit));
        bfs(t.x, t.y);
        t.x = v[t.who].tox; t.y = v[t.who].toy;
        t.dist2 = visit[t.x][t.y] -1;
        if(t.dist2 < 0 || t.fuel < t.dist1 + t.dist2){ans = -1; break;}
        map[v[t.who].x][v[t.who].y] = 0;
        t.fuel = t.fuel - t.dist1 - t.dist2 + 2*t.dist2;
        total--;
    }
    if(ans == -1){
        cout << ans;
    }else{
        cout << t.fuel;
    }
    return 0;
}