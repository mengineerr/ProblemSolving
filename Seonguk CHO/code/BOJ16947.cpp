#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 3001

int n;
vector <int> v[MAX];
bool visit[MAX];
bool cycle[MAX];
int ans[MAX];
bool cycleChk;

struct dat{
    int now, dist;
};
void dfs(int start, int now, int prev){
    if(start == now && prev != -1){
        // 사이클 생성
        cycleChk = true;
        return;
    }
    visit[now] = true;
    for(int next : v[now]){
        if(next == prev) continue;
        if(!visit[next]){
            dfs(start, next, now);
        }else{
            if(next == start) dfs(start, next, now);
        }
    }
    if(cycleChk == true) return;
}
int bfs(int now){
    int dist;
    queue <dat> q;
    memset(visit, 0, sizeof(visit));
    visit[now] = true;
    q.push({now, 0});
    while(!q.empty()){
        now = q.front().now; dist = q.front().dist; q.pop();
        for(int next : v[now]){
            if(visit[next]) continue;
            if(cycle[next]) return dist+1;
            visit[next] = true;
            q.push({next, dist+1});           
        }
    }
}

int main(){
    cin >> n;
    int a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(cycle, false, sizeof(cycle));
    for(int i = 0; i < n; i++){
        // 사이클 확인
        memset(visit, false, sizeof(visit));
        cycleChk = false;
        dfs(i,i,-1);
        if(cycleChk) cycle[i] = true;
    }
    // 최단 거리 계산 BFS
    int dist = 0;
    for(int i = 0; i < n; i++){
        if(cycle[i] == true){
            ans[i] = 0;
        }else{
            dist = bfs(i);
            ans[i] = dist;
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}