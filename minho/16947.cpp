#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 3000 + 1

using namespace std;

int N;
bool visit[MAX];
bool status[MAX];
vector<int> graph[MAX];

struct loc {
    int cur;
    int length;
};

void dfs(int start, int cur, int cnt){
    if(cur == start && cnt >= 2){
        status[start] = true;
        return;
    }

    visit[cur] = true;

    for(int next : graph[cur]){
        if(visit[next] == false)
            dfs(start,next,cnt+1);
        else if(next == start && cnt >= 2)
            dfs(start,next,cnt);
        
        if(status[start] == true) return;
    }
}

int bfs(int cur){
    queue<loc> q;
    int ans;
    q.push({cur,0});
    memset(visit,false,sizeof(visit));
    visit[cur] = true;

    while(!q.empty()){
        loc ncur = q.front();
        q.pop();

        if(status[ncur.cur] == true){
            ans = ncur.length;
            break;
        }

        for(int next : graph[ncur.cur]){
            if(visit[next] == true)
                continue;
            
            visit[next] = true;
            q.push({next,ncur.length+1});
        }
    }

    return ans;
}

int main()
{
    cin >> N;
    int a,b;

    for(int i = 0; i < N; i++){
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    memset(status,false,sizeof(status));

    for(int i = 0; i < N; i++){
        memset(visit,false,sizeof(visit));
        dfs(i,i,0);
    }

    for(int i = 0; i < N; i++){
        if(status[i] == true)
            cout << "0 ";
        else
            cout << bfs(i) << " ";
    }
    cout << "\n";

    return 0;
}
