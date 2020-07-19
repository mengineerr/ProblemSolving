#include <iostream>
#include <vector>

using namespace std;

struct cctv {
    int x;
    int y;
    int type;
};

int N, M = 0;
int val = 64;

void set5(int **map, int i, int j){
    for(int k = i+1; k < N; k++){
        if(map[k][j] >= 1 && map[k][j] <= 5){
            continue;
        }

        if(map[k][j] == 6){
            break;
        }

        map[k][j] = -1;
    }

    for(int k = i-1; k >= 0; k--){
        if(map[k][j] >= 1 && map[k][j] <= 5){
            continue;
        }

        if(map[k][j] == 6){
            break;
        }

        map[k][j] = -1;
    }

    for(int k = j-1; k >= 0 ; k--){
        if(map[i][k] >= 1 && map[i][k] <= 5){
            continue;
        }

        if(map[i][k] == 6){
            break;
        }

        map[i][k] = -1;
    }

    for(int k = j+1; k < M ; k++){
        if(map[i][k] >= 1 && map[i][k] <= 5){
            continue;
        }

        if(map[i][k] == 6){
            break;
        }

        map[i][k] = -1;
    }
}

void sol(int **map, vector<struct cctv> cctv, int num, int limit){
    int ans = 0;

    int **map2 = new int*[N];
    for(int i = 0; i < N; i++)
        map2[i] = new int[M];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            map2[i][j] = map[i][j];
        }
    }

    if(num < limit){
        int type = cctv[num].type;
        int x = cctv[num].x;
        int y = cctv[num].y;
        int idx = 0;

        if(type == 1){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    map2[i][j] = map[i][j];
                }
            }

            // 위
            for(int i = y-1; i >= 0; i--){
                if(map2[i][x] == 6){
                    break;
                }
                if(map2[i][x] >=1 && map2[i][x] <=5){
                    continue;
                }
                map2[i][x] = -1;
            }
            sol(map2,cctv,num+1,limit);

            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    map2[i][j] = map[i][j];
                }
            }

            // 아래
            for(int i = y+1; i < N; i++){
                if(map2[i][x] == 6){
                    break;
                }
                if(map2[i][x] >=1 && map2[i][x] <=5){
                    continue;
                }
                map2[i][x] = -1;
            }
            sol(map2,cctv,num+1,limit);

            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    map2[i][j] = map[i][j];
                }
            }

            // 왼쪽
            for(int i = x-1; i >= 0; i--){
                if(map2[y][i] == 6){
                    break;
                }
                if(map2[y][i] >=1 && map2[y][i] <=5){
                    continue;
                }
                map2[y][i] = -1;
            }
            sol(map2,cctv,num+1,limit);

            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    map2[i][j] = map[i][j];
                }
            }

            // 오른쪽
            for(int i = x+1; i < M; i++){
                if(map2[y][i] == 6){
                    break;
                }
                if(map2[y][i] >=1 && map2[y][i] <=5){
                    continue;
                }
                map2[y][i] = -1;
            }
            sol(map2,cctv,num+1,limit);
        }
        else if(type == 2){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    map2[i][j] = map[i][j];
                }
            }

            // 가로
            for(int i = x-1; i >= 0; i--){
                if(map2[y][i] == 6){
                    break;
                }
                if(map2[y][i] >=1 && map2[y][i] <=5){
                    continue;
                }
                map2[y][i] = -1;
            }
            for(int i = x+1; i < M; i++){
                if(map2[y][i] == 6){
                    break;
                }
                if(map2[y][i] >=1 && map2[y][i] <=5){
                    continue;
                }
                map2[y][i] = -1;
            }

            sol(map2,cctv,num+1,limit);

            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    map2[i][j] = map[i][j];
                }
            }

            // 세로
            for(int i = y-1; i >= 0; i--){
                if(map2[i][x] == 6){
                    break;
                }
                if(map2[i][x] >=1 && map2[i][x] <=5){
                    continue;
                }
                map2[i][x] = -1;
            }
            for(int i = y+1; i < N; i++){
                if(map2[i][x] == 6){
                    break;
                }
                if(map2[i][x] >=1 && map2[i][x] <=5){
                    continue;
                }
                map2[i][x] = -1;
            }

            sol(map2,cctv,num+1,limit);
        }
        else if(type == 3){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    map2[i][j] = map[i][j];
                }
            }

            // 1사분면
            for(int i = y-1; i >= 0; i--){
                if(map2[i][x] == 6){
                    break;
                }
                if(map2[i][x] >=1 && map2[i][x] <=5){
                    continue;
                }
                map2[i][x] = -1;
            }
            for(int i = x+1; i < M; i++){
                if(map2[y][i] == 6){
                    break;
                }
                if(map2[y][i] >=1 && map2[y][i] <=5){
                    continue;
                }
                map2[y][i] = -1;
            }

            sol(map2,cctv,num+1,limit);

            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    map2[i][j] = map[i][j];
                }
            }

            // 2사분면
            for(int i = y-1; i >= 0; i--){
                if(map2[i][x] == 6){
                    break;
                }
                if(map2[i][x] >=1 && map2[i][x] <=5){
                    continue;
                }
                map2[i][x] = -1;
            }
            for(int i = x-1; i >= 0; i--){
                if(map2[y][i] == 6){
                    break;
                }
                if(map2[y][i] >=1 && map2[y][i] <=5){
                    continue;
                }
                map2[y][i] = -1;
            }

            sol(map2,cctv,num+1,limit);

            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    map2[i][j] = map[i][j];
                }
            }

            // 3사분면
            for(int i = y+1; i < N; i++){
                if(map2[i][x] == 6){
                    break;
                }
                if(map2[i][x] >=1 && map2[i][x] <=5){
                    continue;
                }
                map2[i][x] = -1;
            }
            for(int i = x-1; i >= 0; i--){
                if(map2[y][i] == 6){
                    break;
                }
                if(map2[y][i] >=1 && map2[y][i] <=5){
                    continue;
                }
                map2[y][i] = -1;
            }

            sol(map2,cctv,num+1,limit);

            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    map2[i][j] = map[i][j];
                }
            }

            // 4사분면
            for(int i = y+1; i < N; i++){
                if(map2[i][x] == 6){
                    break;
                }
                if(map2[i][x] >=1 && map2[i][x] <=5){
                    continue;
                }
                map2[i][x] = -1;
            }
            for(int i = x+1; i < M; i++){
                if(map2[y][i] == 6){
                    break;
                }
                if(map2[y][i] >=1 && map2[y][i] <=5){
                    continue;
                }
                map2[y][i] = -1;
            }

            sol(map2,cctv,num+1,limit);
        }
        else if(type = 4){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    map2[i][j] = map[i][j];
                }
            }

            // 왼x
            for(int i = y-1; i >= 0; i--){
                if(map2[i][x] == 6){
                    break;
                }
                if(map2[i][x] >=1 && map2[i][x] <=5){
                    continue;
                }
                map2[i][x] = -1;
            }
            for(int i = y+1; i < N; i++){
                if(map2[i][x] == 6){
                    break;
                }
                if(map2[i][x] >=1 && map2[i][x] <=5){
                    continue;
                }
                map2[i][x] = -1;
            }
            for(int i = x+1; i < M; i++){
                if(map2[y][i] == 6){
                    break;
                }
                if(map2[y][i] >=1 && map2[y][i] <=5){
                    continue;
                }
                map2[y][i] = -1;
            }

            sol(map2,cctv,num+1,limit);

            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    map2[i][j] = map[i][j];
                }
            }

            // 오x
            for(int i = y-1; i >= 0; i--){
                if(map2[i][x] == 6){
                    break;
                }
                if(map2[i][x] >=1 && map2[i][x] <=5){
                    continue;
                }
                map2[i][x] = -1;
            }
            for(int i = y+1; i < N; i++){
                if(map2[i][x] == 6){
                    break;
                }
                if(map2[i][x] >=1 && map2[i][x] <=5){
                    continue;
                }
                map2[i][x] = -1;
            }
            for(int i = x-1; i >= 0; i--){
                if(map2[y][i] == 6){
                    break;
                }
                if(map2[y][i] >=1 && map2[y][i] <=5){
                    continue;
                }
                map2[y][i] = -1;
            }

            sol(map2,cctv,num+1,limit);

            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    map2[i][j] = map[i][j];
                }
            }

            // 위x
            for(int i = y+1; i < N; i++){
                if(map2[i][x] == 6){
                    break;
                }
                if(map2[i][x] >=1 && map2[i][x] <=5){
                    continue;
                }
                map2[i][x] = -1;
            }
            for(int i = x-1; i >= 0; i--){
                if(map2[y][i] == 6){
                    break;
                }
                if(map2[y][i] >=1 && map2[y][i] <=5){
                    continue;
                }
                map2[y][i] = -1;
            }
            for(int i = x+1; i < M; i++){
                if(map2[y][i] == 6){
                    break;
                }
                if(map2[y][i] >=1 && map2[y][i] <=5){
                    continue;
                }
                map2[y][i] = -1;
            }

            sol(map2,cctv,num+1,limit);

            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    map2[i][j] = map[i][j];
                }
            }

            // 아래x
            for(int i = y-1; i >= 0; i--){
                if(map2[i][x] == 6){
                    break;
                }
                if(map2[i][x] >=1 && map2[i][x] <=5){
                    continue;
                }
                map2[i][x] = -1;
            }
            for(int i = x-1; i >= 0; i--){
                if(map2[y][i] == 6){
                    break;
                }
                if(map2[y][i] >=1 && map2[y][i] <=5){
                    continue;
                }
                map2[y][i] = -1;
            }
            for(int i = x+1; i < M; i++){
                if(map2[y][i] == 6){
                    break;
                }
                if(map2[y][i] >=1 && map2[y][i] <=5){
                    continue;
                }
                map2[y][i] = -1;
            }

            sol(map2,cctv,num+1,limit);
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map2[i][j] == 0){
                ans++;
            }
        }
    }

    if(val > ans){
        val = ans;
        /*
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                printf("%2d ",map2[i][j]);
            }
            std::cout << "\n";
        }
        std::cout << "\n";
        */
    }
}

int main()
{
    cin >> N >> M;

    int **map = new int*[N];
    for(int i = 0; i < N; i++)
        map[i] = new int[M];

    vector<struct cctv> cctv;
    int temp = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> temp;

            if(temp == -1){
                continue;
            }

            map[i][j] = temp;

            if(map[i][j] > 0 && map[i][j] < 5){
                struct cctv temp;
                temp.x = j;
                temp.y = i;
                temp.type = map[i][j];
                cctv.push_back(temp);
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 5){
                set5(map,i,j);
            }
        }
    }

    int num = cctv.size();

    sol(map,cctv,0,num);

    std::cout << val << "\n";
        
    return 0;
}