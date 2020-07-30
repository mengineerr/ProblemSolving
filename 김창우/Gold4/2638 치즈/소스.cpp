#include <iostream>
#include <queue>
#include <cstring>
#define MAX_MAP 101

using namespace std;

int dirRow[4] = {0, 1, 0, -1};
int dirCol[4] = {1, 0, -1, 0};

int N, M, cheese = 0;;
int map[MAX_MAP][MAX_MAP];
queue<pair<int, int>> cheeseQ;
queue<pair<int, int>> eraseCheeseQ;
queue<pair<int, int>> air;

void checkSpace(){
	queue<pair<int, int>> q;
	q.push(make_pair(1,1));
	while(!q.empty()){
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		for(int i = 0 ; i < 4 ; i++){
			int tempRow = row + dirRow[i];
			int tempCol = col + dirCol[i];
			if(tempRow >= 1 && tempRow <= N && tempCol >= 1 && tempCol <= M){
				if(map[tempRow][tempCol] == 2){
					q.push(make_pair(tempRow, tempCol));
					map[tempRow][tempCol] = 0;
				}
			}
		}
	}
}

void Add_Air()
{
    while (!air.empty()){
        int row = air.front().first;
		int col = air.front().second;
        air.pop();
        for (int i = 0 ; i < 4 ; i++){
            int tempRow = row + dirRow[i];
            int tempCol = col + dirCol[i];
            if(map[tempRow][tempCol] == 2){
                map[tempRow][tempCol] = 0;
                air.push(make_pair(tempRow, tempCol));
            }
        }
    }
}

void solution(){
	int time = 0;
	while(cheese > 0){
		queue<pair<int, int>> tempCheeseQ;
		time++;
		while(!cheeseQ.empty()){
			int row = cheeseQ.front().first;
			int col = cheeseQ.front().second;
			cheeseQ.pop();
			int flag = 0;
			for(int i = 0 ; i < 4 ; i++){
				int tempRow = row + dirRow[i];
				int tempCol = col + dirCol[i];
				if(map[tempRow][tempCol] == 0) flag++;
			}
			if(flag >= 2) eraseCheeseQ.push(make_pair(row, col));
			else tempCheeseQ.push(make_pair(row, col));
		}
		while(!eraseCheeseQ.empty()){
			int row = eraseCheeseQ.front().first;
			int col = eraseCheeseQ.front().second;
			eraseCheeseQ.pop();
			map[row][col] = 0;
			air.push(make_pair(row, col));
			cheese--;
		}
		cheeseQ = tempCheeseQ;
		Add_Air();
	}
	cout << time;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= M ; j++){
			int temp;
			cin >> temp;
			if(temp == 1){
				cheeseQ.push(make_pair(i, j));
				cheese++;
			}
			if(temp == 0) map[i][j] = 2;
			else map[i][j] = temp;
		}
	}

	checkSpace();
	solution();

	return 0;
}
