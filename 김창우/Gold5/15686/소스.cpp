#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#define MAX_NUM 51

using namespace std;

struct House
{
	int row, col;
	int minChicken;
};

struct Chicken
{
	int row, col;
};

House house[MAX_NUM * 2 - 1];
Chicken chicken[14];
queue <pair<int, int>> tempChicken;
int totalDistance = __INT_MAX__;
int N, M;
int numOfHouse = 0, numOfChicken = 0;
int map[MAX_NUM][MAX_NUM];

int calDis(int x1, int y1, int x2, int y2){
	return abs(x1 - x2) + abs(y1 - y2);
}

int calTotalDis(){
	int temp = 0;
	for(int i = 1 ; i <= numOfHouse ; i++){
		temp = temp + house[i].minChicken;
	}
	return temp;
}

void initMinChicken(){
	for (int i = 1 ; i <= numOfHouse ; i++){
		house[i].minChicken = __INT_MAX__;
	}
}

void doComb(int * combArr, int n, int r, int index, int target, int arr){
    if(r == 0){
    	initMinChicken();
    	for(int i = 1 ; i <= numOfHouse ; i++){
			for (int j = 0 ; j < index ; j++){
				int temp = calDis(house[i].row, house[i].col, chicken[combArr[j]].row, chicken[combArr[j]].col);
				house[i].minChicken = min(temp, house[i].minChicken);
			}
		}
		int temp = calTotalDis();
		totalDistance = min(temp, totalDistance);
    }
    else if(target == n) return;
    else{
        combArr[index] = target + 1;
        doComb(combArr, n, r-1, index+1, target+1, arr);
        doComb(combArr, n, r, index, target+1, arr);
    }
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;

	for(int i = 1 ; i <= N ; i++){
		for (int j = 1 ; j <= N ; j++){
			cin >> map[i][j];
			if(map[i][j] == 1){ // house
				numOfHouse++;
				house[numOfHouse].row = i;
				house[numOfHouse].col = j;
				house[numOfHouse].minChicken = __INT_MAX__;
			}
			if(map[i][j] == 2){
				numOfChicken++;
				chicken[numOfChicken].row = i;
				chicken[numOfChicken].col = j;
			}
		}
	}

	int * combArr = new int[M];
	doComb(combArr, numOfChicken, M, 0, 0, numOfChicken);

	cout << totalDistance;

    return 0;
}
