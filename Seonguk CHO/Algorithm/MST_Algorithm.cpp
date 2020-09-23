#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
    Spanning Tree - 그래프 내의 모든 정점을 포함하는 트리
    DFS, BFS을 이용하여 그래프에서 신장 트리를 찾을 수 있음

    1. Kruskal MST 알고리즘
    Greedy 알고리즘을 이용하여 가중치 그래프의 모든 정점을 최소 비용으로 연결
    MST가 최소 비용의 간선으로 구성, 사이클을 포함하지 않음의 조건에 근거하여 최소 비용 간선을 선택
    이전 단계에서 만들어진 신장 트리와는 상관없이 무조건 최소 간선만을 선택
    과정은
    그래프의 간선들을 가중치의 오름차 순으로 정렬한다.
    정렬된 간선리스트에서 순서대로 사이클을 형성하지 않는 간선을 선택한다.
    
*/

struct edge{
    int from;
    int to;
    int val;
}; // 간선 정보 구현

struct comp{
    bool operator()(struct edge e1, struct edge e2){
        return e1.val > e2.val;
    }
};  // 우선순위큐 comp 세팅
priority_queue <struct edge, vector<struct edge>, comp> PQ;
int parent[10001] = {0,};
int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}  // 현재 노드위 부모 노드의 값을 확인 일치하지 않는 경우 재귀형식으로 부모를 찾는다.
bool setUnion(int u, int v){
    u = find(u); v = find(v);  // 두 부모 노드의 값을 찾음
    if(u==v) return false; // 부모가 같으므로 사이클
    if(u<v) parent[u] = v;
    else parent[v] = u;  // 노드의 값이 낮은 것을 부모로 설정
    return true;
}
/*
    2. Prim 알고리즘
    프림 알고리즘은 그래프의 틀을 유지해 나가면서 MST를 형성
    
    과정은
    임의의 시작점 하나를 선택한 후 이 시작점과 연결된 정점들의 거리를 업데이트 한다. 
    선택된 정점들과 연결되어 있는 간선들 중에서 가장 짧은 길이의 간선을 선택하여 연결

    1. 임의의 시작점 하나를 선택
    2. 이 시작점과 연결된 정점들의 거리를 업데이트
    3. 선택된 정점들과 연결되어 있는 간선들 중에서, 가장 짧은 길이의 간선 선택 후 연결
    4. 가장 짧은 간선으로 연결되어 있는 정점 선택, 정점들의 거리 업데이트
    5. 3 ~ 4번의 과정을 N(전체 노드의 갯수) - 1번 만큼 반복

*/
#define MAX 100001

int N, M, ans;
int dist[MAX];
priority_queue <pair<int,int>, vector<pair<int,int>>, greater<>> PQ1;
bool visit[MAX] = {false,};
vector<vector<pair<int,int>>> e;
int k = 0;
void prim(int v){
    visit[v] = true;
    for(auto u : e[v]){
        if(!visit[u.second]){
            PQ1.push({u.first, u.second});
        }
    }
    while(!PQ1.empty()){
        auto w = PQ1.top();
        PQ1.pop();
        if(!visit[w.second]){
            k += w.first;
            prim(w.second);   // 재귀 형식으로 현재 정점에 이어져있는 노드에서 탐색을 시작한다. 
            return;
        }
    }
}
int main(){
    int v, e;
    cin >> v >> e;
    int ans = 0; 
    for(int i = 0; i < v; i++) parent[i] = i;
    for(int i = 0; i < e; i++){
        edge E;
        cin >> E.from >> E.to >> E.val;
        PQ.push(E);
    }
    while (!PQ.empty()){
        int from = PQ.top().from; int to = PQ.top().to;
        if(setUnion(from, to)){
            ans += PQ.top().val;
        }
        PQ.pop();
    }
    cout << ans;
    return 0;
}