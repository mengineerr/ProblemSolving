#include <iostream>

using namespace std;

struct scent {
    int shark;
    int time;
};

struct move {
    int dir[4][4];
};

struct position {
    int x;
    int y;
    bool alive;
};

int dx[4] = {0,0,-1,1}; // up down left right
int dy[4] = {-1,1,0,0};

int main()
{
    int N,M,k;
    cin >> N >> M >> k;

    // Array of structure
    struct scent s[N][N];
    struct position p[M];
    int temp = 0;
    
    // For 0 initialization
    for(int i =0; i < N; i++){
        for(int j = 0; j <N; j++){
            cin >> temp;
            if(temp == 0){
                s[i][j] = {};
            }
            else{
                s[i][j].shark = temp;
                s[i][j].time = 4;
                p[temp-1].x = j;
                p[temp-1].y = i;
                p[temp-1].alive = true;
            }
        }
    }
        
    int cur[M]; // present direction

    for(int i = 0; i < M; i++)
        cin >> cur[i];

    struct move mv[M];  // store movement

    // store each movement;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < 4; j++){
            cin >> mv[i].dir[j][0] >> mv[i].dir[j][1];
            cin >> mv[i].dir[j][2] >> mv[i].dir[j][3];
        }
    }

    int time = 0;
    int curx = 0;
    int cury = 0;
    int cnt = 0;


    while(1){
        if(time > 1000){
            cout << "-1\n";
        }

        cnt = 0;

        for(int i = 0 ;i < N; i++){
            for(int j = 0; j < N; j++){
                if(s[i][j].time == 4){  // shark is located
                    continue;
                }
                if(s[i][j].time > 0){
                    s[i][j].time--;
                    if(s[i][j].time == 0){  // scent is removed
                        s[i][j].shark = 0;
                    }
                }
            }
        }

        for(int i = M-1; i >= 0; i--){
            if(p[i].alive == false){
                continue;
            }

            cnt++;
            curx = p[i].x;
            cury = p[i].y;
            int temp_cur = cur[i];
            int new_cur = 0;
            int newx = 0;
            int newy = 0;

            for(int j =0; j < 4; j++){
                new_cur = mv[i].dir[temp_cur-1][j];

                newx = curx + dx[new_cur-1];
                newy = cury + dy[new_cur-1];

                if(s[newy][newx].shark == 0){   // no scent case
                    break;
                }
            }

            p[i].x = newx;
            p[i].y = newy;
            s[cury][curx].time--;
            s[newy][newx].shark = i+1;
            s[newy][newx].time = 4;
            cur[i] = new_cur;
        }
        
        time++;

        if(cnt == 1){
            cout << time << "\n";
        }
    }

    
    return 0;
}