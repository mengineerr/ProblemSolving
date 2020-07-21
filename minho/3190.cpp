#include <iostream>
#include <deque>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct point{
    int x;
    int y;
};

int main()
{
    int N, K, L = 0;
    cin >> N >> K;

    int **map = new int*[N];
    for(int i = 0; i < N; i++)
        map[i] = new int[N];

    for(int i = 0; i < N ;i++)
        for(int j = 0; j < N; j++)
            map[i][j] = 0;
    
    int x, y;
    for(int i = 0; i < K; i++){
        cin >> y >> x;
        map[y-1][x-1] = 2;
    }

    cin >> L;

    int direction[10001];

    for(int i = 0; i < 10001; i++){
        direction[i] = 0;
    }

    int a = 0;
    char b;
    for(int i = 0; i < L; i++){
        cin >> a >> b;
        if(b == 'D')
            direction[a] = 1;
        else
            direction[a] = -1;
    }

    int time = 0;
    int len = 1;
    int dir = 0;
    int curx, cury = 0;
    deque<struct point> dq; 
    struct point p;
    p.x = 0;
    p.y = 0;
    dq.push_back(p);
    map[0][0] = 1;

    while(1){
        struct point cur;
        cur = dq.back();

        struct point newp;
        int newx = cur.x + dx[dir];
        int newy = cur.y + dy[dir];
        newp.x = newx;
        newp.y = newy;

        if(newx < 0 || newx >= N || newy < 0 || newy >= N || map[newy][newx] == 1){
            cout << time +1  << "\n";
            break;
        }

        if(map[newy][newx] == 2){
            len++;
            dq.push_back(newp);
        }
        else{
            struct point front = dq.front();
            map[front.y][front.x] = 0;
            dq.pop_front();
            dq.push_back(newp);
        }

        map[newy][newx] = 1;

        time++;

        if(direction[time] != 0){
            dir += direction[time];
            if(dir < 0)
                dir += 4;
            if(dir > 3)
                dir -= 4;
        }
    }
        
    return 0;
}