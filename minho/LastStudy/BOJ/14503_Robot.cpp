#include <iostream>

int map[50][50] = {1,};
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int result = 0;

//청소되면 2로
void travel(int x, int y, int dir){
    if(map[x][y] == 0){
        map[x][y] = 2;
        result++;
    }
    
    int new_dir = (dir+3) % 4;

    
    if(map[x][y+1] != 0 && map[x+1][y] !=0 && map[x-1][y] !=0 && map[x][y-1] !=0){
        //후진에 따른 구분 필요
        x -= dx[dir];
        y -= dy[dir];

        if(map[x][y] == 1){
            return;
        }
        else{
            travel(x,y,dir);
        }
    } 
    else if(map[x + dx[new_dir]][y + dy[new_dir]] == 0){
        travel(x + dx[new_dir],y + dy[new_dir],new_dir);
    }
    else{
        travel(x,y,new_dir);
    }

}

int main()
{
    int N, M = 0;
    std::cin >> N >> M;

    int x,y,dir = 0;

    std::cin >> x >> y >> dir;

    for(int i = 0 ; i < N; i++){
        for(int j= 0 ; j < M; j++){
            std::cin >> map[i][j];
        }
    }

    travel(x,y,dir);

    std::cout << result << "\n";
}