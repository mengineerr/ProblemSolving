#include <iostream>
#include <queue>

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
    int M = 0, N = 0;
    std::cin >> M >> N;

    std::queue<std::pair<std::pair<int,int>,int>> q;
    int cnt = 0; // number of 0' tomatos
    int result = 0;
    int day = 0;

    int** map = new int*[N];
    for(int i = 0; i < N; i++){
        map[i] = new int[M];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            std::cin >> map[i][j];
            
            if(map[i][j] == 1){
                q.push(std::make_pair(std::make_pair(i,j),day));
            }
            
            if(map[i][j] == 0){
                cnt++;
            }
        }
    }

    if(cnt == 0){
        std::cout << "0\n";
        return 0;
    }

    int x = 0, y = 0, z = 0;
    int nx = 0, ny = 0;
    int check = 0;

    while(!q.empty()){
        x = q.front().first.first;
        y = q.front().first.second;
        z = q.front().second;
        q.pop();

        if(z > result){
            result = z;
        }

        for(int i = 0; i < 4; i++){
            nx = x + dx[i];
            ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M){
                continue;
            }

            if(map[nx][ny] == -1){
                continue;
            }

            if(map[nx][ny] == 0){
                q.push(std::make_pair(std::make_pair(nx,ny),z + 1));
                map[nx][ny] = 1;
                check++;
            }
        }
    }

    if(cnt > check){
        result = -1;
    }

    std::cout << result << "\n";

    for(int i = 0; i < N; i++){
        delete[] map[i];
    }

    delete[] map;

    return 0;
}