#include <iostream>
#include<algorithm>

#define MAX_NUM 101

using namespace std;

int N, K; // number of items, total weight
int weight[MAX_NUM]; // items weight, value
int value[MAX_NUM];
int answer[MAX_NUM][100001];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 1 ; i <= N ; i++){
		cin >> weight[i] >> value[i];
	}

	for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
        	answer[i][j] = answer[i - 1][j];
            if (weight[i] <= j) {
                answer[i][j] = max(answer[i][j], answer[i - 1][j - weight[i]] + value[i]);
            }
        }
    }

    cout << answer[N][K];

    return 0;
}
