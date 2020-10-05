#include <iostream>

int map[16][16] ={1,};
int N = 0;
int result = 0;

void travel(int x, int y, int dir){
    if(x == N-1 && y == N-1){
        result++;
        return;
    }
    else if(x > N-1 || y > N-1){
        return;
    }
    
    // 가로는 1, 대각선 2, 세로 3
    if(dir == 1){
        if(map[x][y+1] == 0){
            travel(x,y+1,1);
        }
        
        if(map[x][y+1] == 0 && map[x+1][y] == 0 && map[x+1][y+1] == 0){
            travel(x+1,y+1,2);
        }
    }
    else if(dir == 2){
        if(map[x+1][y] == 0){
            travel(x+1,y,3);
        }

        if(map[x][y+1] == 0){
            travel(x,y+1,1);
        }
        
        if(map[x][y+1] == 0 && map[x+1][y] == 0 && map[x+1][y+1] == 0){
            travel(x+1,y+1,2);
        }
    }
    else if(dir == 3){
        if(map[x+1][y] == 0){
            travel(x+1,y,3);
        }
        
        if(map[x][y+1] == 0 && map[x+1][y] == 0 && map[x+1][y+1] == 0){
            travel(x+1,y+1,2);
        }
    }
}

int main()
{
    std::cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N ; j++){
            std::cin >> map[i][j];
        }
    }

    travel(0,1,1);

    std::cout << result << "\n";
}