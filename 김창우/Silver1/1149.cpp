#include <iostream>

using namespace std;

int color[1001][3];
int result[1001][3];

int min(int a, int b) {return a < b ? a : b;}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int numOfHouse;
	int answer;
	
	cin >> numOfHouse;

	for (int i = 0 ; i < numOfHouse ; i++){
		int a, b, c;
		cin >> a >> b >> c;
		color[i+1][0] = a;
		color[i+1][1] = b;
		color[i+1][2] = c;
	}

	result[1][0] = color[1][0];
	result[1][1] = color[1][1];
	result[1][2] = color[1][2];

	for (int i = 2 ; i < numOfHouse + 1 ; i++){
		result[i][0] = min(result[i - 1][1], result[i - 1][2]) + color[i][0];
		result[i][1] = min(result[i - 1][0], result[i - 1][2]) + color[i][1];
		result[i][2] = min(result[i - 1][0], result[i - 1][1]) + color[i][2];
	}

	answer = __INT_MAX__;

	for(int i = 0; i < 3 ; i++){
		if(answer > result[numOfHouse][i]) answer = result[numOfHouse][i];
	}

	cout << answer;

    return 0;
}
