#include <iostream>
#include <queue>
#define MAX_NUM 301

using namespace std;

int dirCol[4] = {1, 0, -1, 0};
int dirRow[4] = {0, 1, 0, -1};

struct Glacier {
	int row, col;
	int current;
	int adder;
};

queue<Glacier> glacierQ;
queue<pair<int, int>> q;
int N, M; // Row, Column
int map[MAX_NUM][MAX_NUM];
int tempMap[MAX_NUM][MAX_NUM];
bool trace[MAX_NUM][MAX_NUM];
int time = 0, mass = 0;

void print(){
	cout << "\n";
	cout << time << "\n";
	for (int i = 1 ; i <= N ; i++){
		for (int j = 1 ; j <= M ; j++){
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void bfs() {
    while (!q.empty()) {
        int tempRow = q.front().first;
        int tempCol = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
        	int row = tempRow + dirCol[i];
        	int col = tempCol + dirRow[i];
        	if (row >= 1 && row <= N && col >= 1 && col <= M){
        		if (tempMap[row][col] != 0 && !trace[row][col]){
        			q.push(pair<int, int>(row, col));
        			trace[row][col] = true;
        			tempMap[row][col] = 0;
        		}
        	}
        }
    }
}

void calGla() {
	queue<Glacier> tempGlacierQ;
	while(!glacierQ.empty()){
		int row = glacierQ.front().row;
		int col = glacierQ.front().col;
		for (int j = 0 ; j < 4 ; j++){
			int tempRow = row + dirRow[j];
			int tempCol = col + dirCol[j];
			if(tempRow >= 1 && tempRow <= N && tempCol >= 1 && tempCol <= M){
				if(map[tempRow][tempCol] == 0) glacierQ.front().adder--;
			}
		}
		tempGlacierQ.push(glacierQ.front());
		glacierQ.pop();
	}
	while(!tempGlacierQ.empty()){
		tempGlacierQ.front().current = tempGlacierQ.front().current + tempGlacierQ.front().adder;
		if(tempGlacierQ.front().current < 0) tempGlacierQ.front().current = 0;
		tempGlacierQ.front().adder = 0;
		map[tempGlacierQ.front().row][tempGlacierQ.front().col] = tempGlacierQ.front().current;
		if(tempGlacierQ.front().current != 0) glacierQ.push(tempGlacierQ.front());
		tempGlacierQ.pop();
	}
}

void claMass(){
	mass = 0;
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= M ; j++){
			tempMap[i][j] = map[i][j];
			trace[i][j] = false;
		}
	}
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= M ; j++){
			if(tempMap[i][j] != 0){
				mass++;
				q.push(make_pair(i, j));
				bfs();
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;

	for (int i = 1 ; i <= N ; i++){
		for (int j = 1 ; j <= M ; j++){
			cin >> map[i][j];
			if(map[i][j] > 0){
				glacierQ.push({i, j, map[i][j], 0});
			}
		}
	}

	while(!glacierQ.empty() && mass < 2){
		time++;
		int numberOfGla = glacierQ.size();
		calGla();
		if(numberOfGla != glacierQ.size()) claMass();
		//print();
	}

	if(mass >= 2) cout << time;
	else cout << "0";

    return 0;
}
