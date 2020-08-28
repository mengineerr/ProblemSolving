#include <iostream>
#include <vector>
#include <queue>
#define MAX 100

using namespace std;

struct loc{
    int y; int x;
};

int map[MAX][MAX] = {0};
int N = 0;
vector<loc> earth[MAX*MAX];
int visit[MAX][MAX] ={0};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int cnt = 0;

int getLength(loc a, loc b){
    return abs(a.y-b.y) + abs(a.x - b.x) - 1;
}

int bridgeLength(int a, int b){
    int val = 987654321;

    for(loc cur:earth[a]){
        for(loc comp:earth[b]){
            int temp = getLength(cur,comp);
            if(temp < val)
                val = temp;
        }
    }

    return val;
}

void bfs(int y, int x, int cnt){
    queue<loc> q;
    q.push({y,x});
    earth[cnt].push_back({y,x});
    visit[y][x] = 1;

    while(!q.empty()){
        loc cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            if(cur.y + dy[i] < 0 || cur.y + dy[i] > N-1 || cur.x + dx[i] < 0 || cur.x + dx[i] > N-1)
                continue;
            if(visit[cur.y + dy[i]][cur.x + dx[i]] == 1 || map[cur.y + dy[i]][cur.x + dx[i]] == 0)
                continue;
            visit[cur.y + dy[i]][cur.x+dx[i]] = 1;
            q.push({cur.y+dy[i],cur.x+dx[i]});
            earth[cnt].push_back({cur.y+dy[i],cur.x+dx[i]});
        }
    }
}

void locNum(){
    
    for(int i = 0;i<N;i++)
        for(int j = 0; j < N; j++){
            if(map[i][j] == 1 && visit[i][j] == 0){
                bfs(i,j,cnt);
                cnt++;
            }
        }

    return;
}

int main()
{
    int ans = 987654321;
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> map[i][j];

    locNum();

    for(int i = 0; i < cnt-1; i++){   // 가장 짧은 다리 구하기
        for(int j = i+1; j < cnt; j++){
            int temp = bridgeLength(i,j);
            if(ans > temp)
                ans = temp;
        }
    }

    cout << ans << "\n";

    return 0;
}