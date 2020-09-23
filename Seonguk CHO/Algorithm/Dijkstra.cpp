#include <iostream>
#include <queue>
#include <vector>

#define MAX 1e9

using namespace std;

/*
    다익스트라 알고리즘이란 그래프에서 최소 비용을 구해야 하는 경우 유용하게 사용되는 알고리즘
    최소 비용 중에서도 주어진 두 노드 사이의 최소 비용인 경로를 찾을 때 사용
    과정은
    1. 시작 노드와 직접적으로 연결된 모든 정점들의 거리를 비교해서 업데이트, 시작 노드를 방문 노드로 체크
    2. 방문한 정점들과 연결되어 있는 정점들 중, 비용이 가장 적게 드는 정점을 선택하고, 해당 정점 체크
    3. 2번 과정에 의해 갱신될 수 있는 정점들의 거리 갱신
    4. 2 ~ 3번 과정을 반복



*/
vector<pair<int,int>> dat[1000];
int main(){
    int v,e;
    cin >> v >> e; // 노드와 엣지의 개수 입력
    int start; 
    cin >> start;  // 시작점 입력 
    for(int i = 0; i < e; i++){
        int from, to, val;
        cin >> from >> to >> val;
        dat[from].push_back({to, val}); // 그래프 정보입력
    }
    int dist[v+1];
    fill(dist, dist+v+1, MAX);
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,start});
    dist[start] = 0; // 시작점은 0으로 표시

    while (!pq.empty()){
        int cost = pq.top().first; int now = pq.top().second;
        pq.pop();
        for(auto v : dat[now]){
            int next = v.first; int nextCost = v.second;
            if(dist[next] > dist[now] + nextCost){
                dist[next] = dist[now] + nextCost;
                pq.push({dist[next], next});
            }
        }
    }
    for(int i = 1; i <= v; i++){
        cout << dist[i] << endl;
    }
    return 0;
}
