#include <iostream>

#define MAX_NUM 102

using namespace std;

struct ROBOT
{
    int x, y, dir;
};

struct ORDER
{
    int count, number;
    char ord;
};

int A, B, N, M;
int map[MAX_NUM][MAX_NUM];
char Rotate[4] = { 'N', 'E', 'S', 'W' };
int dirX[4] = {0,1,0,-1};
int dirY[4] = {1,0,-1,0};

ROBOT robot[MAX_NUM];
ORDER order[MAX_NUM];

void rotateRight (int robotNum, int count){
	int temp = robot[robotNum].dir + (count % 4);
    robot[robotNum].dir = temp > 3 ? temp - 4 : temp;
}

void rotateLeft (int robotNum, int count){
	int temp = robot[robotNum].dir - (count % 4);
    robot[robotNum].dir = temp < 0 ? temp + 4 : temp;
}

int forward (int robotNum, int count){
    for (int i = 1 ; i <= count ; i++) {
        int currentX = robot[robotNum].x;
        int currentY = robot[robotNum].y;
        int tempX = robot[robotNum].x + dirX[robot[robotNum].dir];
        int tempY = robot[robotNum].y + dirY[robot[robotNum].dir];
        int check = map[tempY][tempX];
        if (tempX <= A && tempX >= 1 && tempY >= 1 && tempY <= B) {
            if (check == 0) {
                map[currentY][currentX] = 0;
                map[tempY][tempX] = robotNum;
                robot[robotNum].x = tempX;
                robot[robotNum].y = tempY;
            }
            else
                return check; // robot
        }
        else
            return -1; // wall
    }
    return 0; // ok
}

int convertDir(char ord) {
    for (int i = 0; i < 4; i++)
        if (Rotate[i] == ord)
            return i;
}

void printErrorWall(int x){
	cout << "Robot " << x << " crashes into the wall";
}

void printErrorRobot(int x, int y){
	cout << "Robot " << x << " crashes into robot " << y;
}

void operate (int ord){

	int check = 0;

	switch(order[ord].ord){
			case 'L':
				rotateLeft(order[ord].number, order[ord].count);
			break;
			case 'R':
				rotateRight(order[ord].number, order[ord].count);
			break;
			case 'F':
				check = forward(order[ord].number, order[ord].count);
			break;
	}

	if(check == 0){
		if(ord < M){
			operate(ord + 1);
		}else{
			cout << "OK";
		}
	}else{
		if(check == -1){
			printErrorWall(order[ord].number);
		}else{
			printErrorRobot(order[ord].number, check);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> A >> B; // A : x, B : y
	cin >> N >> M;

	for (int i = 1 ; i <= B ; i++){
		fill_n(map[i], A, 0);
	}

	for (int i = 1 ; i <= N ; i++){
		char dir;
		cin >> robot[i].x >> robot[i].y >> dir;
		robot[i].dir = convertDir(dir);
		map[robot[i].y][robot[i].x] = i;
	}

	for (int i = 1 ; i <= M ; i++){
		cin >> order[i].number >> order[i].ord >> order[i].count;
	}

	operate(1);

    return 0;
}
