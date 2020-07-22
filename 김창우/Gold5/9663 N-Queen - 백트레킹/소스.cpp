#include <iostream>
#include <cmath>

#define MAX_NUM 16

using namespace std;

int column[MAX_NUM];
int N;
int answer;

bool check (int col){
	for (int i = 1 ; i < col ; i++){
		if(column[i] == column[col]) return false;
		if(abs(column[i] - column[col]) == abs(i - col)) return false;
	}
	return true;
}

void DFS(int col){
	if (col > N){
		answer++;
	}else{
		for (int i = 1 ; i <= N ; i++){
			column[col] = i;
			if(check(col)) DFS(col + 1);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1 ; i <= N ; i++){
		column[1] = i;
		DFS(2);
	}

	cout << answer;

    return 0;
}
