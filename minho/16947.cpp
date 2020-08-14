#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 3000 + 1

using namespace std;

int status[MAX];
bool visit[MAX];
int N = 0;

struct loc_info {
    int loc;
    int length;
};

void dfs(vector<vector<int>> map, int cur, int before, int start){
    if(status[start] >= 1)
        return;
    visit[cur] = true;

    // for문 사용법
    for(int next : map[cur]){
        if(next == start && before != start){
            status[next] += 1;
            return;
        }
        if(visit[next] == false){
            dfs(map,next,cur,start);
        }

        if(status[start] == 1) return;
    }
}

int bfs(vector<vector<int>> map, int cur){
    int check[N] = {0,};
    queue<loc_info> q;
    q.push({cur,0});
    int ans = 0;
    check[cur] = 1;

    while(!q.empty()){
        loc_info point = q.front();
        q.pop();

        if(status[point.loc] == 1) {
            ans = point.length;
            break;
        }

        for(int next : map[point.loc]){
            if(check[next] == 0){
                check[next] = 1;
                q.push({next,point.length+1});
            }
        }
    }

    return ans;
}

int main()
{
    cin >> N;

    vector<vector<int>> map(N);

    for(int i = 0; i < N; i++){
        int start = 0,end = 0;
        cin >> start >> end;
        map[start-1].push_back(end-1);
        map[end-1].push_back(start-1);
    }

    // 순환선 구분
    memset(status,0,sizeof(status));
    
    for(int i = 0; i < N; i++){
        memset(visit,false,sizeof(visit));
        dfs(map,i,-1,i);
    }
 
    // 순환선 사이의 거리
    for(int i = 0; i < N; i++){
        if(status[i] == 1){
            cout << "0 ";
        }
        else{
            cout << bfs(map,i) << " ";
        }
    }
    cout << "\n";
    
    return 0;
}