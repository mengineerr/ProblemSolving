#include <iostream>
#include <algorithm>
#include <queue>
#define MAX_MATRIX 5
#define MAX_FISH 17

using namespace std;

int dirRow[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dirCol[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int answer = 0;

struct FISH{
	int row, col, dir, total;
	bool status; // false : death, true : alive
};

FISH fish[MAX_FISH];
FISH shark;
int map[MAX_MATRIX][MAX_MATRIX];

void copyMap(int mapA[MAX_MATRIX][MAX_MATRIX], int mapB[MAX_MATRIX][MAX_MATRIX]){
	for(int i = 1 ; i < MAX_MATRIX ; i++){
		for(int j = 1 ; j < MAX_MATRIX ; j++){
			mapA[i][j] = mapB[i][j];
		}
	}
}

void copyFish(FISH fishA[MAX_FISH], FISH fishB[MAX_FISH]){
	for(int i = 1 ; i < MAX_FISH ; i++){
		fishA[i].row = fishB[i].row;
		fishA[i].col = fishB[i].col;
		fishA[i].dir = fishB[i].dir;
		fishA[i].status = fishB[i].status;
	}
}

void binding(int &row, int &col, int &dir, int num){
	dir = (dir + num) % 8;
	if(dir == 0) dir = 8;
	row = row + dirRow[dir-1];
	col = col + dirCol[dir-1];
}

void movingFish(FISH (&tempFish)[MAX_FISH], int (&tempMap)[MAX_MATRIX][MAX_MATRIX]){
	for(int i = 1 ; i < MAX_FISH ; i++){
		if(!tempFish[i].status){
			for(int j = 0 ; j < 8 ; j++){
				int row = tempFish[i].row;
				int col = tempFish[i].col;
				int dir = tempFish[i].dir;
				binding(row, col, dir, j);
				if(row >= 1 && row <= 4 && col >= 1 && col <= 4 && tempMap[row][col] != -1){
					if(tempMap[row][col] != 0){
						tempFish[tempMap[row][col]].row = tempFish[i].row;
						tempFish[tempMap[row][col]].col = tempFish[i].col;
						tempMap[tempFish[i].row][tempFish[i].col] = tempMap[row][col];
						tempMap[row][col] = i;
						tempFish[i].row = row;
						tempFish[i].col = col;
						tempFish[i].dir = dir;
						break;
					}
					else{
						tempMap[tempFish[i].row][tempFish[i].col] = 0;
						tempMap[row][col] = i;
						tempFish[i].row = row;
						tempFish[i].col = col;
						tempFish[i].dir = dir;
						break;
					}
				}
			}
		}
	}
}

void movingShark(FISH shark, FISH fish[MAX_FISH], int tempMap[MAX_MATRIX][MAX_MATRIX]){
	int copiedMap[MAX_MATRIX][MAX_MATRIX];
	copyMap(copiedMap, tempMap);
	queue<pair<int, int>> q;
	int row = shark.row;
	int col = shark.col;
	for(int i = 0 ; i < 3 ; i++){
		row = row + dirRow[shark.dir - 1];
		col = col + dirCol[shark.dir - 1];
		if(row >= 1 && row <= 4 && col >= 1 && col <= 4 && copiedMap[row][col] != 0){
			q.push(make_pair(row, col));
		}
	}
	
	while(!q.empty()){
		FISH tempShark = shark;
		FISH tempFish[MAX_FISH];
		copyMap(copiedMap, tempMap);
		copyFish(tempFish, fish);
		copiedMap[tempShark.row][tempShark.col] = 0;
		int tempRow = q.front().first;
		int tempCol = q.front().second;
		q.pop();
		tempShark.row = tempRow;
		tempShark.col = tempCol;
		tempShark.dir = tempFish[copiedMap[tempRow][tempCol]].dir;
		tempShark.total = tempShark.total + copiedMap[tempRow][tempCol];
		tempFish[copiedMap[tempRow][tempCol]].status = true;
		copiedMap[tempRow][tempCol] = -1;
		movingFish(tempFish, copiedMap);
		movingShark(tempShark, tempFish, copiedMap);
	}

	answer = max(answer, shark.total);
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for(int i = 1 ; i <= 4 ; i++){
		for(int j = 1 ; j <= 4 ; j++){
			int a, b;
			cin >> a >> b;
			map[i][j] = a; // shark : -1
			fish[a].row = i;
			fish[a].col = j;
			fish[a].dir = b;
			fish[a].status = false;
		}
	}
	
	shark.row = fish[map[1][1]].row;
	shark.col = fish[map[1][1]].col;
	shark.dir = fish[map[1][1]].dir;
	shark.total = map[1][1];
	answer = shark.total;
	fish[map[1][1]].status = true;
	map[1][1] = -1;
	movingFish(fish, map);

	movingShark(shark, fish, map);

	cout << answer;

	return 0;
}
