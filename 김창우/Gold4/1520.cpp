#include <iostream>
#include <queue>
#define MAX_NUM 501

using namespace std;

int M, N;
int map[MAX_NUM][MAX_NUM];
int mem[MAX_NUM][MAX_NUM];

queue <pair<int, int>> answerQ;

int dirRow[4] = { 1, 0, -1, 0 };
int dirCol[4] = { 0, 1, 0, -1 };

int cal(int row, int col){
	if (mem[row][col] != -1) return mem[row][col];
	if (row == 1 && col == 1){
		mem[row][col] = 1;
		return 1;
	}
	else if (row == 0 && col == 0){
		return 0;
	}
	else{
		int originalValue = map[row][col];
		int tempPair[4][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
		for(int i = 0 ; i < 4 ; i++){
			int tempRow = row + dirRow[i];
			int tempCol = col + dirCol[i];
			if (tempRow >= 1 && tempRow <= M && tempCol >= 1 && tempCol <= N){
				int tempValue = map[tempRow][tempCol];
				if (tempValue > originalValue){
					tempPair[i][0] = tempRow;
					tempPair[i][1] = tempCol;
				}
			}
		}
		mem[row][col] = cal(tempPair[0][0], tempPair[0][1]) + cal(tempPair[1][0], tempPair[1][1]) + cal(tempPair[2][0], tempPair[2][1]) + cal(tempPair[3][0], tempPair[3][1]);
		return mem[row][col];
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> M >> N;

	for (int i = 1 ; i <= M ; i++){
		for (int j = 1 ; j <= N ; j++){
			cin >> map[i][j];
			mem[i][j] = -1;
		}
	}

	int answer = cal(M, N);

	cout << answer;

    return 0;
}
