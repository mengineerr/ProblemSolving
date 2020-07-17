#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

#define MAX_NUM 26

using namespace std;

int map[MAX_NUM][MAX_NUM];
bool trace[MAX_NUM][MAX_NUM];
int N;
int defX[4] = {-1, 0, 1, 0};
int defY[4] = {0, 1, 0, -1};
int numOfHouse;

queue<pair<int, int>> q;
queue<int> numQ;


void bfs() {
    while (!q.empty()) {
        int tempX = q.front().first;
        int tempY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){
        	int ax = tempX + defX[i];
        	int ay = tempY + defY[i];
        	if (ax >= 1 && ax <= N && ay >= 1 && ay <= N){
        		if (map[ax][ay] == 1 && !trace[ax][ay]){
        			q.push(pair<int, int>(ax, ay));
        			trace[ax][ay] = true;
        			map[ax][ay] = 0;
        			numOfHouse++;
        		}
        	}
        }
    }
}


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int totallNum = 0;

	cin >> N;

	for (int i = 1 ; i < N + 1 ; i++){
		string str;
		cin >> str;
		for (int j = 1 ; j < N + 1 ; j++){
			map[i][j] = stoi(str.substr(j - 1, 1));
		}
	}
	
	for (int i = 1 ; i < N + 1 ; i++){
		for (int j = 1 ; j < N + 1 ; j++){
			if(map[i][j] == 1){
				numOfHouse = 1;
				q.push(pair<int, int>(i, j));
				trace[i][j] = true;
        		map[i][j] = 0;
				bfs();
				numQ.push(numOfHouse);
				totallNum++;
			}
		}
	}
	
	cout << totallNum << "\n";

	int * answer = new int [totallNum];

	for (int i = 0 ; i < totallNum ; i++){
		answer[i] = numQ.front();
		numQ.pop();
	}

	sort(answer, answer+totallNum);

	for (int i = 0 ; i < totallNum ; i++){
		cout << answer[i] << " ";
	}

    return 0;
}
