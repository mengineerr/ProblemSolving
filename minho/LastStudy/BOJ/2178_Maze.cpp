#include <iostream>
#include <queue>

int map[100][100] = {0,};
int visit[100][100] = {0,};
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int N, M = 0;
int result = 0;

void dfs()
{
    int x,y = 0;
    int cnt = 0;
    int x_new,y_new = 0;
    std::queue<std::pair<std::pair<int,int>,int>> q;

    q.push(std::make_pair(std::make_pair(0,0),1));
    visit[0][0] = 1;

    while(!q.empty()){
        x = q.front().first.first;
        y = q.front().first.second;
        cnt = q.front().second;

        q.pop();

        if(x == N-1 && y == M-1){
            result = cnt;
            return;
        }

        for(int i = 0; i < 4 ; i++){
            x_new = x + dx[i];
            y_new = y + dy[i];

            if(x_new < 0 || x_new > N-1 || y_new < 0 || y_new > M-1 ){
                continue;
            }

            if(map[x_new][y_new] != 1){
                continue;
            }

            if(visit[x_new][y_new] == 1){
                continue;
            }

            visit[x_new][y_new] = 1;
            q.push(std::make_pair(std::make_pair(x_new,y_new),cnt+1));
        }
    }

   

    

    return;
}

int main()
{
    
    
    std::cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d",&map[i][j]);
        }
    }

    
    dfs();

    std::cout << result << "\n";
}