#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX_NUM 11

using namespace std;

int N, answer = __INT_MAX__;
int population[MAX_NUM];
bool connect[MAX_NUM][MAX_NUM];

bool check(bool temp[MAX_NUM], int a){
	int count = 1;
	queue<int> q;
	bool visit[MAX_NUM];
	fill_n(visit, MAX_NUM, false);
	for(int i = 1 ; i <= N ; i++){
		if(temp[i]){
			q.push(i);
			visit[i] = true;
			break;
		}
	}
	while(!q.empty()){
		int num = q.front();
		q.pop();
		for(int i = 1 ; i <= N ; i++){
			if(connect[num][i] && temp[i] && !visit[i]){
				visit[i] = true;
				count++;
				q.push(i);
			}
		}
	}
	if(count == a) return true;
	else return false;
}

void cal(vector<int> temp){
	bool selectA[MAX_NUM];
	bool selectB[MAX_NUM];
	int selectsA = temp.size();
	int selectsB = N - selectsA;
	queue<int> q;

	fill_n(selectA, MAX_NUM, false);
	fill_n(selectB, MAX_NUM, true);

	for(int i = 0 ; i < temp.size() ; i++){
		selectA[temp[i]] = true;;
		selectB[temp[i]] = false;;
	}

	if(check(selectA, selectsA)){
		if(check(selectB, selectsB)){
			int a = 0;
			int b = 0;
			for(int i = 1 ; i <= N ; i++){
				if(selectA[i]) a = a + population[i];
				if(selectB[i]) b = b + population[i];
			}
			answer = min(answer, abs(a-b));
		}
	}
}

void Comb(int k){
	vector<int> n;
	vector<int> ind;

	for(int i = 1 ; i <= N ; i++) n.push_back(i);

	for(int i = 1 ; i <= k ; i++) ind.push_back(1);

	for(int i = 1 ; i <= N - k ; i++) ind.push_back(0);

	sort(ind.begin(), ind.end());

	do{
		vector<int> v;
		for(int i = 0 ; i < ind.size() ; i++){
			if(ind[i] == 1) v.push_back(n[i]);
		}
		cal(v);
	}while(next_permutation(ind.begin(), ind.end()));
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for(int i = 1 ; i <= N ; i++){
		cin >> population[i];
		fill_n(connect[i], N+1, false);
	}

	for(int i = 1 ; i <= N ; i++){
		int temp = 0;
		cin >> temp;
		for(int j = 1; j <= temp ; j++){
			int temptemp = 0;
			cin >> temptemp;
			connect[i][temptemp] = true;
		}
	}

	int check = answer;

	for(int i = 1 ; i <= N / 2 ; i++) Comb(i);

	if(answer != check)	cout << answer;
	else cout << "-1";

	return 0;
}
