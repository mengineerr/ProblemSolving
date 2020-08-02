#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX_MAP 100
#define INF __INT_MAX__

using namespace std;

int dirRow[4] = {1,0,-1,0};
int dirCol[4] = {0,1,0,-1};

char map[MAX_MAP][MAX_MAP];
int R, C, N;
vector<int> orders;
bool checkClusters[MAX_MAP][MAX_MAP];
bool visit[MAX_MAP][MAX_MAP];
vector<pair<int, int>> checkClusterss;

int weight(int row, int col){
    int Cnt = 0;
    for (int i = row + 1; i < R; i++){
        if (map[i][col] == 'x'){
            if (checkClusters[i][col] == true) return INF;
            else return Cnt;
        }
        else if (map[i][col] == '.') Cnt++;
    }
    return Cnt;
}

void movecheckClusters(){
	int H = INF - 1;
    for (int i = 0; i < checkClusterss.size(); i++){
        int x = checkClusterss[i].first;
        int y = checkClusterss[i].second;
        int Temp_H = weight(x, y);

        if (Temp_H == INF) continue;
        else H = min(H, Temp_H);
    }
 
    sort(checkClusterss.begin(), checkClusterss.end());
    for (int i = checkClusterss.size() - 1 ; i >= 0 ; i--){
        int x = checkClusterss[i].first;
        int y = checkClusterss[i].second;
        map[x][y] = '.';
        map[x + H][y] = 'x';
    }
}
	
void BFS(int a, int b){
	queue<pair<int, int>> q;
    q.push(make_pair(a, b));
    visit[a][b] = true;
	while(!q.empty()){
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		for(int i = 0 ; i < 4 ; i++){
			int tempRow = row + dirRow[i];
			int tempCol = col + dirCol[i];
			if(tempRow >= 0 && tempRow < R && tempCol >= 0 && tempCol < C){
				if(map[tempRow][tempCol] == 'x' && !visit[tempRow][tempCol]){
					q.push(make_pair(tempRow, tempCol));
					visit[tempRow][tempCol] = true;
				}
			}
		}
	}
}

bool searchcheckClusters(){
	for(int i = 0 ; i < C ; i++){
		if(map[R - 1][i] == 'x' && !visit[R - 1][i]){
			BFS(R - 1, i);
		}
	}

	bool checkClustersInAir = false;

	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			if(map[i][j] == 'x' && !visit[i][j]){
				checkClusterss.push_back(make_pair(i, j));
				checkClusters[i][j] = true;
				checkClustersInAir = true;
			}
		}
	}
	return checkClustersInAir;
}

bool throwStick(int height, char order){
    if (order == 'L'){
        for(int i = 0 ; i < C; i++){
            if(map[height][i] == 'x'){
                map[height][i] = '.';
                return true;
            }
        }
    }
    else{
        for (int i = C - 1; i >= 0; i--){
            if (map[height][i] == 'x'){
                map[height][i] = '.';
                return true;
            }
        }
    }
    return false;
}

void solution(){
	for (int i = 0; i < orders.size(); i++)
    {
        checkClusterss.clear();
        memset(visit, false, sizeof(visit));
        memset(checkClusters, false, sizeof(checkClusters));
 
        char Order_C;
 
        if (i % 2 == 0) Order_C = 'L';
        else Order_C = 'R';
        
        if (!throwStick(R - orders[i], Order_C)) continue;
        if (!searchcheckClusters()) continue;
        else movecheckClusters();
    }
	for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++)
        {
            cout << map[i][j];
        }
        cout << "\n";
    }
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> R >> C;

	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			cin >> map[i][j];
		}
	}

	cin >> N;

	for(int i = 0 ; i < N ; i++){
		int temp;
		cin >> temp;
		orders.push_back(temp);
	}

	solution();

    return 0;
}
