#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX_MAP 101

using namespace std;

struct INFO{
	int ROW, COL, DIS;
};

int dirRow[4] = {1,0,-1,0};
int dirCol[4] = {0,1,0,-1};
int N;
int ANSWER = __INT_MAX__;
int MAP[MAX_MAP][MAX_MAP];
bool VISIT[MAX_MAP][MAX_MAP];

bool isPossible(int ROW, int COL){
	if(ROW >= 1 && ROW <= N && COL >= 1 && COL <= N) return true;
	else return false;
}

void findBridge(int ROW, int COL){
	queue<INFO> Q;
	Q.push({ROW, COL, 0});
	bool tempVisit[MAX_MAP][MAX_MAP];
	memset(tempVisit, false, sizeof(tempVisit));
	while(!Q.empty()){
		int row = Q.front().ROW;
		int col = Q.front().COL;
		int dis = Q.front().DIS;
		Q.pop();
		for(int i = 0 ; i < 4 ; i++){
			int tempRow = row + dirRow[i];
			int tempCol = col + dirCol[i];
			if(isPossible(tempRow, tempCol)){
				if(MAP[tempRow][tempCol] == 0 && !tempVisit[tempRow][tempCol]){
					Q.push({tempRow, tempCol, dis + 1});
					tempVisit[tempRow][tempCol] = true;
				}
				if(MAP[tempRow][tempCol] == 1 && !VISIT[tempRow][tempCol]){
					ANSWER = min(ANSWER, dis);
					return;
				}
			}
		}
	}
}

void findEdge(int ROW, int COL){
	queue<pair<int, int>> Q;
	queue<pair<int, int>> edgeQ;
	Q.push(make_pair(ROW, COL));
	VISIT[ROW][COL] = true;
	while(!Q.empty()){
		int row = Q.front().first;
		int col = Q.front().second;
		Q.pop();
		int count = 0;
		for(int i = 0 ; i < 4 ; i++){
			int tempRow = row + dirRow[i];
			int tempCol = col + dirCol[i];
			if(isPossible(tempRow, tempCol)){
				if(MAP[tempRow][tempCol] == 1 && !VISIT[tempRow][tempCol]){
					Q.push(make_pair(tempRow, tempCol));
					VISIT[tempRow][tempCol] = true;
				}
				if(MAP[tempRow][tempCol] == 0) count++;
			}
		}
		if(count > 0){
			edgeQ.push(make_pair(row, col));
		}
	}
	while(!edgeQ.empty()){
		int row = edgeQ.front().first;
		int col = edgeQ.front().second;
		edgeQ.pop();
		findBridge(row, col);
	}
}


void solution(){
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			if(MAP[i][j] == 1 && !VISIT[i][j]){
				memset(VISIT, false, sizeof(VISIT));
				findEdge(i, j);
			}
		}
	}

	cout << ANSWER;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N;

	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			cin >> MAP[i][j];
		}
	}

	solution();

    return 0;
}
