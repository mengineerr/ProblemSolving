#include <iostream>
#include <vector>
#include <cstring>
#define MAX_MAP 41
#define MAX_STICKER 11
#define MAX_STICKERS 101

using namespace std;

int N, M, K; // row, col, stickers
int MAP[MAX_MAP][MAX_MAP];
int ROW = 0, COL = 0;
int stickers[MAX_STICKER][MAX_STICKER];
int total = 0;
int answer = 0;

void rotateSticker(){
	int tempRow = ROW;
	int tempCol = COL;
	int tempStickers[MAX_STICKER][MAX_STICKER];
	memset(tempStickers, 0, sizeof(tempStickers));
	for(int i = 1 ; i <= COL ; i++){
		for(int j = 1 ; j <= ROW ; j++){
			tempStickers[i][j] = stickers[ROW-j+1][i];
		}
	}
	ROW = tempCol;
	COL = tempRow;
	memset(stickers, 0, sizeof(stickers));
	for(int i = 1 ; i <= ROW ; i++){
		for(int j = 1 ; j <= COL ; j++){
			stickers[i][j] = tempStickers[i][j];
		}
	}
}

void fill_map(int row, int col){
	for(int i = 1 ; i <= ROW ; i++){
		for(int j = 1 ; j <= COL ; j++){
			if(stickers[i][j] == 1){
				MAP[i+row-1][j+col-1] = 1;
			}
		}
	}
}

bool moveSticker(int row, int col){
	for(int i = 1 ; i <= ROW ; i++){
		for(int j = 1 ; j <= COL ; j++){
			if(stickers[i][j] == 1 && MAP[i+row-1][j+col-1] == 1) return false;
		}
	}
	return true;
}

void attachSticker(){
	for(int i = 1 ; i <= N - ROW + 1 ; i++){
		for(int j = 1 ; j <= M - COL + 1 ; j++){
			if(moveSticker(i, j)){
				fill_map(i, j);
				answer = answer + total;
				return;
			}
		}
	}
	for(int i = 0 ; i < 3 ; i++){
		rotateSticker();
		for(int m = 1 ; m <= N - ROW + 1 ; m++){
			for(int n = 1 ; n <= M - COL + 1 ; n++){
				if(moveSticker(m, n)){
					fill_map(m, n);
					answer = answer + total;
					return;
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M >> K;

	memset(MAP, 0, sizeof(MAP));

	for(int i = 1 ; i <= K ; i++){
		memset(stickers, 0, sizeof(stickers));
		total = 0;
		cin >> ROW >> COL;
		for(int j = 1 ; j <= ROW ; j++){
			for(int m = 1 ; m <= COL ; m++){
				cin >> stickers[j][m];
				if(stickers[j][m] == 1) total++;
			}
		}
		attachSticker();
	}

	cout << answer;

    return 0;
}
