#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int **map;
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

struct location{
    int x;
    int y;
    int wall;
    int distance;
};

int bfs(){
    queue<location> q;
    struct location start;
    start.x = 0;
    start.y = 0;
    start.wall = 0;
    start.distance = 1;
    q.push(start);

    int visit[N][M][2];
    memset(visit,0,sizeof(visit));

    visit[0][0][0] = 1;

    while(!q.empty()){
        struct location cur = q.front();
        q.pop();

        if(cur.x == M-1 && cur.y == N-1)
            return cur.distance;

        for(int i = 0; i < 4; i++){
            if(cur.x + dx[i] < 0 || cur.x + dx[i] > M-1 || cur.y + dy[i] < 0 || cur.y + dy[i] > N-1)
                continue;
            if(map[cur.y + dy[i]][cur.x + dx[i]] == 0 && visit[cur.y + dy[i]][cur.x + dx[i]][cur.wall] == 0){
                struct location newloc;
                newloc.x = cur.x + dx[i];
                newloc.y = cur.y + dy[i];
                newloc.wall = cur.wall;
                newloc.distance = cur.distance + 1;
                visit[newloc.y][newloc.x][newloc.wall] = newloc.distance;
                q.push(newloc);
                
            }
            else if(map[cur.y + dy[i]][cur.x + dx[i]] == 1 && cur.wall == 0 && visit[cur.y + dy[i]][cur.x + dx[i]][cur.wall+1] == 0){
                struct location newloc;
                newloc.x = cur.x + dx[i];
                newloc.y = cur.y + dy[i];
                newloc.wall = cur.wall + 1;
                newloc.distance = cur.distance + 1;
                visit[newloc.y][newloc.x][newloc.wall] = newloc.distance;
                q.push(newloc);
            }
        }
    }
    
    return -1;
}

int main()
{
    cin >> N >> M;
    map = new int*[N];
    for(int i = 0; i < N; i++)
        map[i] = new int[M];
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%1d",&map[i][j]);

    cout << bfs() << "\n";

    return 0;
}
