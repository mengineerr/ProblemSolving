#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX_MATRIX 1001

using namespace std;

int rowDir[4] = { -1, 0, 1, 0 };
int colDir[4] = { 0, 1, 0, -1 };

struct INFO {
	int row, col, chance, dis;
};

int N, M;
int map[MAX_MATRIX][MAX_MATRIX];

void binding(int& row, int& col, int num) {
	row = row + rowDir[num];
	col = col + colDir[num];
}

int findMinDis() {
	if(N == 1 && M == 1) return 1;
	queue <INFO> infoQ;
	bool trace[MAX_MATRIX][MAX_MATRIX][2];
	infoQ.push({ 1, 1, 1, 1 });
	int leastDis = __INT_MAX__;
	while (!infoQ.empty()) {
		int newRow = infoQ.front().row;
		int newCol = infoQ.front().col;
		int newChance = infoQ.front().chance;
		int newDis = infoQ.front().dis;
		infoQ.pop();
		for (int i = 0; i < 4; i++) {
			int tempRow = newRow, tempCol = newCol;
			binding(tempRow, tempCol, i);
			if (tempRow == N && tempCol == M) {
				leastDis = min(leastDis, newDis + 1);
			}
			else{
				if (tempRow <= N && tempRow >= 1 && tempCol <= M && tempCol >= 1) {
					if(map[tempRow][tempCol] == 1 && newChance == 1){
						infoQ.push({ tempRow, tempCol, 0, newDis + 1 });
						trace[tempRow][tempCol][newChance-1] = true;
					}
					if(map[tempRow][tempCol] == 0 && !trace[tempRow][tempCol][newChance]){
						infoQ.push({ tempRow, tempCol, newChance, newDis + 1 });
						trace[tempRow][tempCol][newChance] = true;
					}
				}
			}
		}
	}
	return leastDis;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= M; j++) {
			map[i][j] = stoi(str.substr(j-1, 1));
		}
	}

	int distance = findMinDis();

	if(distance == __INT_MAX__) cout << "-1";
	else cout << distance;

	return 0;
}
