#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_NUM 3001

using namespace std;

int N;
vector<int> station[MAX_NUM];
bool stationStatus[MAX_NUM];
bool visit[MAX_NUM];
bool checkCircle;

void checkLine(int startNum, int number, int count){
	if(number == startNum && count >= 2){
		checkCircle = true;
		return;
	}
	visit[number] = true;
	for(int i = 0 ; i < station[number].size() ; i++){
		int next = station[number][i];
		if(!visit[next]) checkLine(startNum, next, count + 1);
		else{
			if(next == startNum && count >= 2) checkLine(startNum, next, count);
		}
		if(checkCircle) return;
	}
}

int findDis(int number){
	memset(visit, false, sizeof(visit));
	queue<pair<int, int>> q;
	q.push(make_pair(number, 0));
	visit[number] = true;
	while(!q.empty()){
		int current = q.front().first;
		int count = q.front().second;
		q.pop();
		if(stationStatus[current]) return count;
		for(int i = 0 ; i < station[current].size() ; i++){
			int next = station[current][i];
			if(!visit[next]){
				visit[next] = true;
				q.push(make_pair(next, count + 1));
			}
		}
	}
}

void solution(){
	for(int i = 1 ; i <= N ; i++){
		memset(visit, false, sizeof(visit));
		checkCircle = false;
		checkLine(i, i, 0); // start, current, count
		if(checkCircle){
			stationStatus[i] = true;
		}
	}
	for(int i = 1 ; i <= N ; i++){
		if(stationStatus[i]) cout << "0 ";
		else{
			cout << findDis(i) << " ";
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N;

	memset(stationStatus, false, sizeof(stationStatus));

	for(int i = 1 ; i <= N ; i++){
		int a, b;
		cin >>  a >> b;
		station[a].push_back(b);
		station[b].push_back(a);
	}

	solution();

    return 0;
}
