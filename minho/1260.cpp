#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

void dfs(vector<vector<int>> graph, int cur){
    int check[graph.size()] = {0,};
    check[cur] = 1;

    stack<int> s;
    s.push(cur);

    int temp = 0;
    int next = 0;

    cout << cur+1 << " ";

    while(!s.empty()){
        temp = s.top();
        s.pop();

        for(int i = 0; i < graph[temp].size(); i++){
            next = graph[temp][i];
            if(check[next] == 0){
                cout << next+1 << " ";
                check[next] = 1;
                s.push(temp);
                s.push(next);
                break;
            }
        }
    }

    cout << "\n";
}

void bfs(vector<vector<int>> graph, int cur){
    int check[graph.size()] = {0,};
    check[cur] = 1;

    queue<int> q;
    q.push(cur);

    int temp = 0;

    while(!q.empty()){
        temp = q.front();
        q.pop();
        cout << temp + 1 << " ";

        
        for(int i = 0; i < graph[temp].size(); i++){
            if(check[graph[temp][i]] == 0){
                q.push(graph[temp][i]);
                check[graph[temp][i]] = 1;
            }
        }
        
    }

    cout << "\n";
}

int main()
{
    int N, M ,V = 0;
    std::cin >> N >> M >> V;

    vector<vector<int>> graph;

    vector<int> element;

    for(int i = 0; i < N; i++){
        graph.push_back(element);
    }

    int start, end = 0;

    for(int i = 0; i < M; i++){
        std::cin >> start >> end;
        graph[start-1].push_back(end-1);
        graph[end-1].push_back(start-1);
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < graph[i].size();j++){
            sort(graph[i].begin(),graph[i].end());
        }
    }

    dfs(graph,V-1);
    bfs(graph,V-1);
    
    return 0;
}
