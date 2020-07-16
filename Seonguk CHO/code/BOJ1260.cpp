#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX 1001
vector <int> graph[MAX];
int visit[MAX];
int n, m, v;

void dfs(int now){
    cout << now << " ";
    visit[now] = 1;
    int nx;
    for(int i = 0; i < graph[now].size(); i++){
        nx = graph[now][i];
        if(visit[nx] == 0){
            dfs(nx);
        }
    }
    return;
}
void bfs(int v){
    int now,nx;
    queue <int> q;
    q.push(v);
    visit[v] = 1;
    while(!q.empty()){
        now = q.front();
        cout << now << " ";
        q.pop();
        for(int i = 0; i < graph[now].size(); i++){
            nx = graph[now][i];
            if(visit[nx] == 0){
                q.push(nx);
                visit[nx] = 1;
            }
        }
    }
}
void init(){
    for(int i = 0; i < MAX; i++) visit[i] = 0;
}
int main(){
    cin >> n >> m >> v;
    int temp, temp1;
    for(int i = 0; i < m; i++){
        cin >> temp >> temp1;
        graph[temp].push_back(temp1);
        graph[temp1].push_back(temp);
    }
    for(int i = 0; i< n; i++) sort(graph[i].begin(), graph[i].end());
    init();
    dfs(v);
    cout << endl;
    init();
    bfs(v);
    return 0;
}
