#include <iostream>
#include <queue>
#define MAX_NUM 101
#define MAX_TIME 10001

using namespace std;

int dirX[4] = {0, -1, 0, 1};
int dirY[4] = {1, 0, -1, 0};
int direction[MAX_TIME];
int N, K, L;
int map[MAX_NUM][MAX_NUM];
int snakeDir = 0;
queue <pair<int,int>> snake;

void print(){
	for(int i = 1; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void rotateRight (){
	int temp = snakeDir - 1;
    snakeDir = temp < 0 ? temp + 4 : temp;
}

void rotateLeft (){
	int temp = snakeDir + 1;
    snakeDir = temp > 3 ? temp - 4 : temp;
}

bool forward (){
    int currentX = snake.front().first;
    int currentY = snake.front().second;
    int tempX = currentX + dirX[snakeDir];
    int tempY = currentY + dirY[snakeDir];
    int check = map[tempX][tempY];

    if (tempX <= N && tempX >= 1 && tempY >= 1 && tempY <= N) {
        if (check == 0) { // nothing
            queue <pair<int,int>> temp;
            temp.push(make_pair(tempX,tempY));
            map[tempX][tempY] = 1;
            map[currentX][currentY] = 0;
            while(snake.size() > 1){
                map[snake.front().first][snake.front().second] = 1;
                temp.push(make_pair(snake.front().first,snake.front().second));
                snake.pop();
            }
            map[snake.front().first][snake.front().second] = 0;
            snake.pop();
            snake = temp;
        }
        else if(check == -1) { // apple
            queue <pair<int,int>> temp;
            temp.push(make_pair(tempX,tempY));
            map[tempX][tempY] = 1;
            map[currentX][currentY] = 0;
            while(!snake.empty()){
                map[snake.front().first][snake.front().second] = 1;
                temp.push(make_pair(snake.front().first,snake.front().second));
                snake.pop();
            }
            snake = temp;
        }
        else if(check == 1) { // snake
            return true;
        }
    }
    else{ // wall
        return true;
    }
    return false; // ok
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	cin >> K;

	for(int i = 1 ; i <= N ; i++){ // init map with 0
		fill_n(map[i], N, 0);
	}

	fill_n(direction, MAX_TIME - 1, 0);

	map[1][1] = 1; // 1 : snake;
	snake.push(make_pair(1,1));

	for (int i = 0 ; i < K ; i++){
		int a, b;
		cin >> a >> b;
		map[a][b] = -1; // -1 : apple
	}

	cin >> L;

	for (int i = 0 ; i < L ; i++){
		int a;
		char b;
		cin >> a >> b;
		if(b == 'D'){ // turn right
			direction[a] = 1;
		}else if(b == 'L'){ // turn left
			direction[a] = -1;
		}
	}

	bool flag = false;
	int totalTime = 0;

	while(!flag){
		totalTime++;
		if(direction[totalTime] == 1){
			flag = forward();
			rotateRight();
		}
		else if(direction[totalTime] == -1){
			flag = forward();
			rotateLeft();
		}
		else flag = forward();
		//print();
	}

	cout << totalTime;

    return 0;
}
