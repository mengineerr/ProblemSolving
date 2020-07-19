#include <iostream>
#include <algorithm>

#define MAX_NUM 9

using namespace std;

struct CCTV
{
    int type, n, m;
};

CCTV cctv[8];
int rotation[6] = {0, 4, 2, 4, 4, 1};
int N, M, cameraNum;
int map[MAX_NUM][MAX_NUM];
int minNum = MAX_NUM * MAX_NUM;

void fill_map(int dir, CCTV cctv){
	dir %= 4;
	if (dir == 0){
		for (int x = cctv.m + 1; x <= M; x++){
            if(map[cctv.n][x] == 6) break;
			map[cctv.n][x] = -1;
        }
	}else if (dir == 1){
		for (int y = cctv.n - 1; y > 0; y--){
            if(map[y][cctv.m] == 6) break;
			map[y][cctv.m] = -1;
        }
	}else if (dir == 2){
		for (int x = cctv.m - 1; x > 0; x--){
            if(map[cctv.n][x] == 6) break;
			map[cctv.n][x] = -1;
        }
	}else{
		for (int y = cctv.n + 1; y <= N; y++){
            if(map[y][cctv.m] == 6) break;
			map[y][cctv.m] = -1;
        }
	}
}

void copyMap(int a[MAX_NUM][MAX_NUM], int b[MAX_NUM][MAX_NUM]){
	for (int i = 1 ; i <= N ; i++){
		for (int j = 1 ; j <= M ; j++){
			a[i][j] = b[i][j];
		}
	}
}

void cal (int cctvIndex){
	if (cctvIndex == cameraNum){
		int count = 0;
		for (int i = 1 ; i <= N ; i++){
			for (int j = 1 ; j <= M ; j++){
				if (map[i][j] == 0) count++;
			}
		}
		minNum = min(count, minNum);
	}

	int backUp[MAX_NUM][MAX_NUM];
	int type = cctv[cctvIndex].type;

	for (int dir = 0 ; dir < rotation[type] ; dir++){
		copyMap(backUp, map);

		switch(type){
			case 1:
				fill_map(dir, cctv[cctvIndex]);
			break;
			case 2:
				fill_map(dir, cctv[cctvIndex]);
				fill_map(dir + 2, cctv[cctvIndex]);
			break;
			case 3:
				fill_map(dir, cctv[cctvIndex]);
				fill_map(dir + 1, cctv[cctvIndex]);
			break;
			case 4:
				fill_map(dir, cctv[cctvIndex]);
				fill_map(dir + 1, cctv[cctvIndex]);
				fill_map(dir + 2, cctv[cctvIndex]);
			break;
			case 5:
				fill_map(dir, cctv[cctvIndex]);
				fill_map(dir + 1, cctv[cctvIndex]);
				fill_map(dir + 2, cctv[cctvIndex]);
				fill_map(dir + 3, cctv[cctvIndex]);
			break;
		}

		cal(cctvIndex + 1);

		copyMap(map, backUp);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1 ; i <= N ; i++){
		for (int j = 1 ; j <= M ; j++){
			cin >> map[i][j];
			if(map[i][j] != 0 && map[i][j] != 6){
				cctv[cameraNum].type = map[i][j];
				cctv[cameraNum].n = i;
				cctv[cameraNum].m = j;
				cameraNum++;
			}
		}
	}

	cal(0);

	cout << minNum;

    return 0;
}
