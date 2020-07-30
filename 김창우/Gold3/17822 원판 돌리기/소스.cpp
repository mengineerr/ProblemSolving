#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX_NUM 50

using namespace std;

int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

struct ROTATE{
	int x, d, k;
};

struct DATA{
	int x, y, value;
};

vector<vector<int>> circles;
vector<ROTATE> rules;
int N, M, T;
bool visit[MAX_NUM][MAX_NUM];

void changeNumber(){
	double count = 0;
	double total = 0;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			if(circles[i][j] != -1){
				total = total + circles[i][j];
				count++;
			}
		}
	}
	double average = total / count;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			if(circles[i][j] != -1){
				if(circles[i][j] < average) circles[i][j]++;
				else if(circles[i][j] > average) circles[i][j]--;
			}
		}
	}
}

bool BFS(int x, int y){
	int check = 0;
	queue<DATA> q;
	q.push({x, y, circles[x][y]});
	while(!q.empty()){
		int oriX = q.front().x;
		int oriY = q.front().y;
		int oriData = q.front().value;
		q.pop();
		for(int i = 0 ; i < 4 ; i++){
			int tempX = oriX + dirX[i];
			int tempY = oriY + dirY[i];
			if(tempY == M) tempY = 0;
			if(tempY < 0) tempY = M - 1;
			if(tempX >= 0 && tempX < N && tempY >= 0 && tempY < M){
				if(circles[tempX][tempY] == oriData && !visit[tempX][tempY]){
					q.push({tempX, tempY, oriData});
					visit[tempX][tempY] = true;
					circles[tempX][tempY] = -1;
					check++;
				}
			}
		}
	}
	if(!check) return false;
	else{
		circles[x][y] = -1;
		return true;
	}
}

bool checkNumbers(){
	int check = 0;
	memset(visit, false, sizeof(visit));
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			if(circles[i][j] != -1){
				visit[i][j] = true;
				check = check + BFS(i, j);
			}
		}
	}
	if(!check) return true;
	else return false;
}

void rotateCircles(int x, int d, int k){
	for(int i = 1 ; i * x <= N ; i++){
		int tempNum = 0;
		tempNum = (x*i) - 1;
		vector<int> temp;
		switch(d){
			case 0:
				for(int i = M - k ; i < M ; i++){
					temp.push_back(circles[tempNum][i]);
				}
				for(int i = 0 ; i < M - k ; i++){
					temp.push_back(circles[tempNum][i]);
				}
			break;
			case 1:
				for(int i = k ; i < M ; i++){
					temp.push_back(circles[tempNum][i]);
				}
				for(int i = 0 ; i < k ; i++){
					temp.push_back(circles[tempNum][i]);
				}
			break;
		}
		circles[tempNum].swap(temp);
	}
}

void solution(){
	for(int i = 0 ; i < T ; i++){
		int xi = rules[i].x;
		int di = rules[i].d;
		int ki = rules[i].k;
		rotateCircles(xi, di, ki);

		if(checkNumbers()) changeNumber();
		
	}
	int answer = 0;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			if(circles[i][j] != -1){
				answer = answer + circles[i][j];
			}
		}
	}
	cout << answer;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> T;

	for(int i = 0 ; i < N ; i++){
		vector<int> temp;
		for(int j = 0 ; j < M ; j++){
			int tempNum;
			cin >> tempNum;
			temp.push_back(tempNum);
		}
		circles.push_back(temp);
	}

	for(int i = 0 ; i < T ; i++){
		ROTATE rotate;
		cin >> rotate.x >> rotate.d >> rotate.k;
		rules.push_back(rotate);
	}

	solution();

	return 0;
}
