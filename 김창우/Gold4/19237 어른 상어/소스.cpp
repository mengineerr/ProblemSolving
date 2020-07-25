#include <iostream>
#define MAX_MAP 21

using namespace std;

int dirRow[4] = {-1, 1, 0, 0};
int dirCol[4] = {0, 0, -1, 1};

struct SHARK {
	int currentRow, currentCol, dir;
	int nextRow, nextCol;
	int prior[5][5];
	bool status; // true : alive, false : death
};

SHARK shark[401];
int N, M, K;
int map[MAX_MAP][MAX_MAP];
int trace[MAX_MAP][MAX_MAP];
int numberOfShark = 0, numberOfShark_temp = 0, time = 0;

void binding(int &row, int &col, int num){
	row = row + dirRow[num-1];
	col = col + dirCol[num-1];
}

void changeTrace(){
	for(int i = 1 ; i <= N ; i++){
		for (int j = 1 ; j <= N ; j++){
			if(trace[i][j] > 1) trace[i][j]--;
			else if(trace[i][j] == 1){
				trace[i][j] = 0;
				map[i][j] = 0;
			}
		}
	}
}

void movingShark(){
	for (int i = 1 ; i <= numberOfShark ; i++){
		if(shark[i].status){
			int row = shark[i].currentRow;
			int col = shark[i].currentCol;
			int dir = shark[i].dir;
			int flag = false;
			for (int j = 0 ; j < 4 ; j++){
				int tempRow = row;
				int tempCol = col;
				binding(tempRow, tempCol, shark[i].prior[dir][j+1]);
				if(tempRow >= 1 && tempRow <= N && tempCol >= 1 && tempCol <= N){
					if(map[tempRow][tempCol] == 0){
						shark[i].nextRow = tempRow;
						shark[i].nextCol = tempCol;
						shark[i].dir = shark[i].prior[dir][j+1];
						flag = true;
						break;
					}
				}
			}
			if(!flag){
				for (int j = 0 ; j < 4 ; j++){
					int tempRow = row;
					int tempCol = col;
					binding(tempRow, tempCol, shark[i].prior[dir][j+1]);
					if(tempRow >= 1 && tempRow <= N && tempCol >= 1 && tempCol <= N){
						if(map[tempRow][tempCol] == -i){
							shark[i].nextRow = tempRow;
							shark[i].nextCol = tempCol;
							shark[i].dir = shark[i].prior[dir][j+1];
							break;
						}
					}
				}
			}
		}
	}

	changeTrace();

	for(int i = 1 ; i <= numberOfShark ; i++){
		if(shark[i].status){
			int row = shark[i].currentRow;
			int col = shark[i].currentCol;
			if(K > 1) map[row][col] = -i;
			shark[i].currentRow = shark[i].nextRow;
			shark[i].currentCol = shark[i].nextCol;
			int value = map[shark[i].currentRow][shark[i].currentCol];
			row = shark[i].currentRow;
			col = shark[i].currentCol;
			if(value == 0 || value == -i){
				map[row][col] = i;
				trace[row][col] = K;
			}else{
				int temp = map[row][col];
				if(temp > i){
					map[row][col] = i;
					trace[row][col] = K;
					shark[temp].status = false;
					numberOfShark_temp--;
				}else{
					shark[i].status = false;
					numberOfShark_temp--;
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M >> K;

	for (int i = 1 ; i <= N ; i++){
		for (int j = 1 ; j <= N ; j++){
			cin >> map[i][j];
			if(map[i][j] != 0){
				shark[map[i][j]].currentRow = i;
				shark[map[i][j]].currentCol = j;
				shark[map[i][j]].nextRow = i;
				shark[map[i][j]].nextCol = j;
				shark[map[i][j]].status = true;
				trace[i][j] = K;
				numberOfShark++;
				numberOfShark_temp++;
			}
		}
	}

	for (int i = 1 ; i <= numberOfShark ; i++){
		cin >> shark[i].dir;
	}

	for (int i = 1 ; i <= numberOfShark ; i++){
		for (int j = 1 ; j <= 4 ; j++){
			cin >> shark[i].prior[j][1] >> shark[i].prior[j][2] >> shark[i].prior[j][3] >> shark[i].prior[j][4];
		}
	}

	while(time < 1000 && numberOfShark_temp > 1){
		time++;
		movingShark();
	}

	if(numberOfShark_temp > 1) cout << "-1";
	else cout << time;

    return 0;
}
