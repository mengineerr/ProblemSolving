#include <iostream>
#include <queue>

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int N = 0;
    std::cin >> N;

    int low = 100;
    int high = 2;
    int loc = 0; // height of rain

    int** map = new int*[N];
    for(int i = 0; i < N; i++){
        map[i] = new int[N];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cin >> map[i][j];

            if(map[i][j] > high) high = map[i][j];
            if(map[i][j] < low) low = map[i][j];
        }
    }

    int result = 0;
    int cnt = 0;
    std::queue<std::pair<int,int>> q;
    int x = 0, y = 0;
    int nx = 0, ny = 0;
    bool visit[N][N] = {false,};

    for(int i = low-1; i <= high-1; i++){
        loc = i;
        cnt = 0;
        
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N ; k++){
                visit[j][k] = false;
            }
        }

        for(int j = 0; j < N; j++){
            for(int k = 0; k < N ; k++){
                if(map[j][k] > loc && visit[j][k] == false){
                    visit[j][k] = true;
                    q.push(std::make_pair(j,k));
                    
                    while(!q.empty()){
                        x = q.front().first;
                        y = q.front().second;
                        q.pop();

                        for(int l = 0; l < 4 ; l++){
                            nx = x + dx[l];
                            ny = y + dy[l];

                            if(nx < 0 || nx >= N || ny < 0 || ny >= N){
                                continue;
                            }

                            if(map[nx][ny] > loc && visit[nx][ny] == false){
                                visit[nx][ny] = true;
                                q.push(std::make_pair(nx,ny));
                            }
                        }
                    }

                    cnt++;
                    //std::cout << loc << " : " << "(" << j << " , " << k << ")\t" << cnt << "\n";
                }
            }
        }

        if(cnt > result){
            result = cnt;
        }
    }

    std::cout << result << "\n";

    for(int i = 0; i < N; i++){
        delete[] map[i];
    }

    delete[] map;

    return 0;
}