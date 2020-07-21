#include <iostream>

using namespace std;

int N,M,fuel = 0;
int **map;
int **person;

struct taxi {
    int x;
    int y;
};

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int use = 987654321;
int idx = 0;

void check(int y, int x, int p, int q, int loc, int used){
    if(y == p && x == q){
        use = used;
        idx = loc;
        return;
    }
    if(used == N*N){
        return;
    }

    for(int i = 0; i < 4; i++){
        if(y + dy[i] < 0 || y + dy[i] >= N || x + dx[i] < 0 || x + dx[i] >=N){
            continue;
        }
        check(y + dy[i], x + dx[i], p,q, loc, used + 1);
    }
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
        cout << total << "\n";

        idx = 0;
        use = 987654321;

        // 출발지에서 손님까지
        for(int i = M-1; i >= 0; i--){
            if(person[i][0] == -1){ // skip case
                continue;
            }
            check(taxi.y, taxi.x, person[i][0],person[i][1], i, 0);
        }

        if(use == N*N){
            cout << "-1";
            return 0;
        }
        
        // 최단거리 손님으로 이동 및 연료소모
        taxi.y = person[idx][0];
        taxi.x = person[idx][1];
        person[idx][0] = -1;
        person[idx][1] = -1;

        fuel -= use;

        if(total < 0){
            cout << "-1\n";
            return 0;
        }

        use = 987654321;
        idx = 0;

        // 손님에서 목적지까지
        for(int i = M-1; i >= 0; i--){
            if(person[i][2] == -1){ // skip case
                continue;
            }

            check(taxi.y, taxi.x, person[i][2],person[i][3], i, 0);
        }

        if(use == N*N){
            cout << "-1";
            return 0;
        }

        // 최단거리 손님으로 이동 및 연료소모
        taxi.y = person[idx][2];
        taxi.x = person[idx][3];
        person[idx][2] = -1;
        person[idx][3] = -1;

        fuel -= use;

        if(fuel < 0){
            cout << "-1\n";
            return 0;
        }

        fuel += 2 * use;

        total--;
    }

    return 0;
}