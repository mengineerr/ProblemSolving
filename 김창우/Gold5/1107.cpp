#include <iostream>
#include <cmath>

using namespace std;

int min(int a, int b) {return a < b ? a : b;}

bool buttons[10];

int check (int num){
	string str = to_string(num);
	int len = str.length();
	for (int i = 0; i < len ; i++){
		if (buttons[str[i] - '0']) return 0;
	}
	return len;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M; // channel, broken buttons
	
	cin >> N >> M;

	for (int i = 0 ; i < M ; i++){ // check broken buttons
		int x;
		cin >> x;
		buttons[x] = true;
	}

	int answer = abs(N - 100);

	for (int i = 0 ; i <= 1000000 ; i++){
		int click = check(i);
		if (click){
			answer = min(abs(N - i) + click, answer);
		}
	}

	cout << answer;

    return 0;
}
