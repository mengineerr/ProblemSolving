#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N = 0, M = 0, K = 0;
int **map;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

struct location {
    int x; int y; int wall;
};

int sol(){
    int dist[N][M][K+1];
    memset(dist,0,sizeof(dist));

    queue<location> q;
    q.push({0,0,0});
    dist[0][0][0] = 1;

    while(!q.empty()){
        struct location cur = q.front();
        q.pop();

        if(cur.x == M-1 && cur.y == N-1)
            return dist[cur.y][cur.x][cur.wall];

        for(int i = 0; i < 4; i++){
            if(cur.x + dx[i] < 0 || cur.x + dx[i] > M-1 || cur.y + dy[i] < 0 || cur.y + dy[i] > N-1)
                continue;
            if(map[cur.y + dy[i]][cur.x + dx[i]] == 0 && dist[cur.y + dy[i]][cur.x + dx[i]][cur.wall] == 0){
                dist[cur.y + dy[i]][cur.x + dx[i]][cur.wall] = dist[cur.y][cur.x][cur.wall] + 1;
                q.push({cur.x + dx[i],cur.y + dy[i],cur.wall});
            }
            else if(cur.wall < K && map[cur.y + dy[i]][cur.x + dx[i]] == 1 && dist[cur.y + dy[i]][cur.x + dx[i]][cur.wall] == 0){
                dist[cur.y + dy[i]][cur.x + dx[i]][cur.wall + 1] = dist[cur.y][cur.x][cur.wall] + 1;
                q.push({cur.x + dx[i],cur.y + dy[i],cur.wall + 1});
            }
        }

    }


    return -1;
}

int main()
{
    cin >> N >> M >> K;
    map = new int*[N];
    for(int i = 0; i < N; i++)
        map[i] = new int[M];
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%1d",&map[i][j]);

    cout << sol() << "\n";
    
    return 0;
}