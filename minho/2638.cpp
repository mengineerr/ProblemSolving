#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N = 0,M = 0;
int **map;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

struct location{
    int y; int x;
};

int main()
{
    cin >> N >> M;
    int cheese = 0;

    map = new int*[N];
    for(int i = 0; i < N; i++)
        map[i] = new int [M];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] == 1)
                cheese++;
        }
    
    int time = 0;

    while(cheese > 0){
        int visit[N][M][2];
        memset(visit,0,sizeof(visit));
        queue<location> q;

        q.push({0,0});
        visit[0][0][0] = 1;

        while(!q.empty()){
            location cur = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                if(cur.x + dx[i] < 0 || cur.x + dx[i] > M-1 || cur.y + dy[i] < 0 || cur.y + dy[i] > N-1)
                    continue;
                if(visit[cur.y+dy[i]][cur.x+dx[i]][0] == 1)
                    continue;
                if(map[cur.y+dy[i]][cur.x+dx[i]] == 1){
                    visit[cur.y+dy[i]][cur.x+dx[i]][1]++;
                    continue;
                }
                visit[cur.y+dy[i]][cur.x+dx[i]][0] = 1;
                q.push({cur.y+dy[i],cur.x+dx[i]});
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(visit[i][j][1] >= 2){
                    map[i][j] = 0;
                    cheese--;
                }
            }
        }

        time++;
    }

    cout << time << "\n";

    return 0;
}