#include <iostream>
#include <cstring>
#include <queue>

#define MAX_NUM 1000

using namespace std;

int map[MAX_NUM][MAX_NUM];
int trace[MAX_NUM][MAX_NUM];
int M, N;
int defX[4] = {-1, 0, 1, 0};
int defY[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        int tempX = q.front().first;
        int tempY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){
        	int ax = tempX + defX[i];
        	int ay = tempY + defY[i];
        	if (ax >= 0 && ax < N && ay >= 0 && ay < M){
        		if (map[ax][ay] == 0 && trace[ax][ay] == -1){
        			trace[ax][ay] = trace[tempX][tempY] + 1;
        			q.push(pair<int, int>(ax, ay));
        		}
        	}
        }
    }
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int day = 0;
	
	cin >> M >> N;

	for (int i = 0 ; i < N ; i++){
		for (int j = 0 ; j < M ; j++){
			cin >> map[i][j];
			trace[i][j] = -1;
			if (map[i][j] == 1){
				q.push(pair<int, int>(i, j));
				trace[i][j] = 0;
			}
		}
	}

	bfs();

	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < M; j++) { 
			day = max(day,trace[i][j]); 
		} 
	}

	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < M; j++) { 
			if(map[i][j] == 0 && trace[i][j] == -1)
				day = -1;
		} 
	}

	cout << day;

    return 0;
}
