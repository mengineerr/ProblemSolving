#include <iostream>
#include <queue>

using namespace std;

int N,M,fuel = 0;
int **map;
int **person;

struct taxi {
    int x;
    int y;
};

struct point {
    int x;
    int y;
    int distance;
};

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int check(int y, int x, int p, int q, int loc){
    queue<struct point> queue;
    int use = 987654321;

    int check[N][N];
    for(int i =0; i < N; i++)
        for(int j = 0; j < N; j++)
            check[i][j] = 0;

    check[y][x] = 1;
    struct point tmp;
    tmp.y = y;
    tmp.x = x;
    tmp.distance = 0;

    queue.push(tmp);

    while(!queue.empty()){
        struct point node = queue.front();
        queue.pop();

        int curx = node.x;
        int cury = node.y;
        int curdis = node.distance;
        
        if(cury == p && curx == q){
            if(use > curdis)
                use = curdis;
        }

        for(int i = 0; i < 4; i++){
            if(cury + dy[i] < 0 || cury + dy[i] >= N || curx + dx[i] < 0 || curx + dx[i] >=N)
                continue;
            if(check[cury+dy[i]][curx+dx[i]] == 0 && map[cury+dy[i]][curx+dx[i]] == 0){
                check[cury+dy[i]][curx+dx[i]] = 1;
                
                struct point newnode;
                newnode.x = curx + dx[i];
                newnode.y = cury + dy[i];
                newnode.distance = curdis + 1;

                queue.push(newnode);
            }
        }
    }

    return use;
}

int main()
{
    cin >> N >> M >> fuel;

    map = new int*[N];
    for(int i = 0; i<N; i++){
        map[i] = new int[N];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    struct taxi taxi;

    cin >> taxi.y >> taxi.x;

    taxi.y--;
    taxi.x--;

    int a,b,c,d;
    
    person = new int*[M];
    for(int i = 0; i < M; i++){
        person[i] = new int[4];
    }

    for(int i = 0; i < M; i++){
        cin >> a >> b >> c >> d;
        person[i][0] = a-1;
        person[i][1] = b-1;
        person[i][2] = c-1;
        person[i][3] = d-1;
    }

    int total = M;

    while(1){
        if(total == 0){
            cout << fuel << "\n";
            return 0;
        }   

        int used = 987654321;
        int temp = 0;
        int idx = 0;

        // 출발지에서 손님까지
        for(int i = M-1; i >= 0; i--){
            if(person[i][0] == -1){ // skip case
                continue;
            }
            temp = check(taxi.y, taxi.x, person[i][0],person[i][1], i);
            if(temp < used){
                used = temp;
                idx = i;
            }
            if(temp == used){
                if(person[idx][0] > person[i][0]){
                    idx = i;
                }
                else if(person[idx][0] == person[i][0] && person[idx][1] > person[i][1]){
                    idx = i;
                }
            }
        }

        if(used == 987654321){
            cout << "-1\n";
            return 0;
        }
        
        // 최단거리 손님으로 이동 및 연료소모
        taxi.y = person[idx][0];
        taxi.x = person[idx][1];
        person[idx][0] = -1;
        person[idx][1] = -1;
        fuel -= used;

        if(fuel < 0){
            cout << "-1\n";
            return 0;
        }

        // 손님에서 목적지까지
        used = check(taxi.y, taxi.x, person[idx][2],person[idx][3], idx);

        if(used == 987654321){
            cout << "-1\n";
            return 0;
        }

        // 최단거리 손님으로 이동 및 연료소모
        taxi.y = person[idx][2];
        taxi.x = person[idx][3];
        person[idx][2] = -1;
        person[idx][3] = -1;
        fuel -= used;

        if(fuel < 0){
            cout << "-1\n";
            return 0;
        }

        fuel += 2 * used;
        total--;
    }

    return 0;
}