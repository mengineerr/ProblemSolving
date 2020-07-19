#include <iostream>

using namespace std;

struct map {    // 상어의 위치
    int shark;
    int time;
    bool islocated;
};

struct position {   // 현재 상어 위치 및 이동 정보
    int x;
    int y;
    bool isalive;
    int dir;
    int movement[5][5];
};

int dx[5] = {999,0,0,-1,1}; // up(1) down(2) left(3) right(4)
int dy[5] = {999,-1,1,0,0};

int main()
{
    int N,M,K;
    cin >> N >> M >> K;

    struct map map[N][N];
    struct position position[M+1];

    int temp = 0;
    int time = 0;
    int curx = 0;
    int cury = 0;
    int curdir = 0;
    int newx = 0;
    int newy = 0;
    int newdir = 0;

    for(int i =0 ; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> temp;

            if(temp == 0){
                map[i][j].shark = 0;
                map[i][j].time = 0;
                map[i][j].islocated = false;
            }
            else{
                map[i][j].shark = temp;
                map[i][j].time = K;
                map[i][j].islocated = true;
                position[temp].x = j;
                position[temp].y = i;
                position[temp].isalive = true;
            }
        }
    }

    for(int i = 1; i <= M; i++){
        cin >> position[i].dir;
    }

    for(int i = 1; i <= M; i++){
        for(int j = 1; j <=4; j++){
            for(int k = 1; k <= 4; k++)
                cin >> position[i].movement[j][k];
        }
    }

    while(1){
        if(time > 1000){    // 1000초 초과
            cout << "-1\n";
            break;
        }

        //if(time > 26) break;

        temp = 0;

        for(int i = 1; i <= M; i++){
            if(position[i].isalive == true)
                temp++;
        }

        if(temp == 1){   // 1번 상어만 남았을 때
            cout << time << "\n";
            break;
        }
        

        //  새로운 위치 찾기
        for(int i = 1; i <= M; i++){
            if(position[i].isalive == false){
                continue;
            }

            curx = position[i].x;
            cury = position[i].y;
            curdir = position[i].dir;
            bool flag = false;

            // 빈공간 찾기
            for(int j = 1; j <= 4; j++){
                newdir = position[i].movement[curdir][j];
                newx = curx + dx[newdir];
                newy = cury + dy[newdir];

                if(newx < 0 || newx > N-1 || newy < 0 || newy > N-1){
                    continue;
                }

                if(map[newy][newx].time == 0){
                    flag = true;
                    break;
                }
            }

            // 빈공간이 없으면
            if(flag == false){
                for(int j = 1; j <= 4; j++){
                    newdir = position[i].movement[curdir][j];
                    newx = curx + dx[newdir];
                    newy = cury + dy[newdir];

                    if(newx < 0 || newx > N-1 || newy < 0 || newy > N-1){
                        continue;
                    }

                    if(i == map[newy][newx].shark)
                        break;
                }
            }

            position[i].x = newx;
            position[i].y = newy;
            position[i].dir = newdir;
            //map[newy][newx].islocated = true;
            map[cury][curx].islocated = false;

            //cout << i << " " << position[i].dir << " : ( " << newy << " , " << newx << " )\n";
        }
        
        
        // 상어 위치 갱신
        for(int i = 1; i <= M; i++){
            if(position[i].isalive == false){
                continue;
            }
            // 이미 상어가 위치해 있다면 죽인다
            if(map[position[i].y][position[i].x].islocated == true){
                position[i].isalive = false;
                //cout << "kill " << i << "\n";
                continue;
            }

            map[position[i].y][position[i].x].shark = i;
            map[position[i].y][position[i].x].time = K;
            map[position[i].y][position[i].x].islocated = true;
        }

        // 향기 조정
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                // 상어가 없다면 시간 감소
                if(!map[i][j].islocated && map[i][j].time > 0){
                    map[i][j].time--;
                }

                // 향기 사라진 경우
                if(map[i][j].time == 0){
                    map[i][j].shark = 0;
                }
                //cout << map[i][j].shark << " ";
            }
            //cout << "\n";
        }
        //cout << "\n";


        time++;
    }
    
    return 0;
}