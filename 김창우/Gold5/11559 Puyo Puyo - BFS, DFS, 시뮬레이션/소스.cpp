#include <iostream>
#include <queue>

using namespace std;

int driRow[4] = {0, 1, 0, -1};
int dirCol[4] = {1, 0, -1, 0};
char data[12][6];
bool check[12][6];

void resetCheck(){
	for(int i = 0 ; i < 12 ; i++){
		for(int j = 0 ; j < 6 ; j++){
			check[i][j] = false;
		}
	}
}

void cleanPuyo(){
	for(int i = 0 ; i < 6 ; i++){
		queue<char> q;
		int count = 0;
		for(int j = 11 ; j >= 0 ; j--){
			if(data[j][i] != '.'){
				q.push(data[j][i]);
				count++;
			}
		}
		for(int k = 11 ; k > 11 - count ; k--){
			data[k][i] = q.front();
			q.pop();
		}
		for(int k = 11 - count ; k >= 0 ; k--){
			data[k][i] = '.';
		}
	}
}

int BFS(int row, int col){ // true : Puyo Puyo, false : nothing
	int count = 1;
	char chr = data[row][col];
	queue<pair<int, int>> q;
	queue<pair<int, int>> eraseQ;
	q.push(make_pair(row, col));
	eraseQ.push(make_pair(row, col));
	while(!q.empty()){
		int qRow = q.front().first;
		int qCol = q.front().second;
		q.pop();
		for(int i = 0 ; i < 4 ; i++){
			int tempRow = qRow + driRow[i];
			int tempCol = qCol + dirCol[i];
			if(tempRow >= 0 && tempRow < 12 && tempCol >= 0 && tempCol < 6){
				if(data[tempRow][tempCol] == chr && !check[tempRow][tempCol]){
					q.push(make_pair(tempRow, tempCol));
					eraseQ.push(make_pair(tempRow, tempCol));
					count++;
					check[tempRow][tempCol] = true;
				}
			}
		}
	}
	if(count >= 4){
		while(!eraseQ.empty()){
			int qRow = eraseQ.front().first;
			int qCol = eraseQ.front().second;
			eraseQ.pop();
			data[qRow][qCol] = '.';
		}
		return 1;
	}
	else return 0;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for(int i = 0 ; i < 12 ; i++){
		cin >> data[i][0] >> data[i][1] >> data[i][2] >> data[i][3] >> data[i][4] >> data[i][5];
	}

	int answer = 0;
	int puyopuyo = 1;

	while(puyopuyo > 0){
		resetCheck();
		puyopuyo = 0;
		for(int i = 0 ; i < 12 ; i++){
			for(int j = 0 ; j < 6 ; j++){
				if(data[i][j] != '.' && !check[i][j]){
					check[i][j] = true;
					puyopuyo = puyopuyo + BFS(i, j);
				}
			}
		}
		if(puyopuyo > 0) answer++;
		cleanPuyo();
	}

	cout << answer;

	return 0;
}
