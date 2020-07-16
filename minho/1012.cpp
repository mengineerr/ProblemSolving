#include <iostream>
#include <stack>

using namespace std;

int M, N, K = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void dfs(int i, int j, int **map){
    map[i][j] = -1;

    for(int k = 0; k < 4; k++){
        if(i + dx[k] < 0 || i + dx[k] >= N || j + dy[k] < 0 || j + dy[k] >= M){
            continue;
        }

        if(map[i+dx[k]][j+dy[k]] == 1){
            dfs(i+dx[k],j+dy[k],map);
        }
    }
}

int input()
{
    cin >> M >> N >> K;

    int **map = new int*[N];
    for(int i = 0; i < N; i++){
        map[i] = new int[M];
    }

    for(int i = 0; i < N ; i++){
        for(int j = 0; j < M; j++){
            map[i][j] = 0;
        }
    }

    int x, y = 0;

    for(int i = 0; i < K; i++){
        cin  >> x >> y;
        map[y][x] = 1;
    }

    int cnt = 0;

    for(int i = 0; i < N ; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 1){
                dfs(i,j,map);
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    int T = 0;
    cin >> T;

    int *ans = new int[T];

    for(int i =0; i < T; i++){
        ans[i] = input();
    }

    for(int i =0; i < T; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}