#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX_NUM 501

using namespace std;

int N, answer = 0;
int map[MAX_NUM][MAX_NUM];
int mem[MAX_NUM][MAX_NUM];

int dirRow[4] = { 1, 0, -1, 0 };
int dirCol[4] = { 0, 1, 0, -1 };

int DP(int row, int col){
	if(mem[row][col] != -1) return mem[row][col];
	mem[row][col] = 1;

	for(int i = 0 ; i < 4 ; i++){
		int tempRow = row + dirRow[i];
		int tempCol = col + dirCol[i];
		if(tempRow >= 1 && tempRow <= N && tempCol >= 1 && tempCol <= N){
			if(map[tempRow][tempCol] > map[row][col]){
				mem[row][col] = max(DP(tempRow, tempCol) + 1, mem[row][col]);
			}
		}
	}
	return mem[row][col];
}

void solution(){
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			answer = max(DP(i, j), answer);
		}
	}
	cout << answer;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N;

	for (int i = 1 ; i <= N ; i++){
		for (int j = 1 ; j <= N ; j++){
			cin >> map[i][j];
			mem[i][j] = -1;
		}
	}

	solution();

    return 0;
}
