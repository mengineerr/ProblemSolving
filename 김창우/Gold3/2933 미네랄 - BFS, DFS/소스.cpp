#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX_MAP 100
#define INF 987654321

using namespace std;

int dirRow[4] = {1,0,-1,0};
int dirCol[4] = {0,1,0,-1};

char map[MAX_MAP][MAX_MAP];
int R, C, N;
vector<int> orders;
bool Cluster[MAX_MAP][MAX_MAP];
bool visit[MAX_MAP][MAX_MAP];
vector<pair<int, int>> clusters;

int weight(int row, int col){
    int Cnt = 0;
    for (int i = row + 1; i < R; i++)
    {
        if (map[i][col] == 'x')
        {
            if (Cluster[i][col] == true) return INF;
            else return Cnt;
        }
        else if (map[i][col] == '.') Cnt++;
    }
    return Cnt;
}

void moveCluster(){
	int H = INF - 1;
    for (int i = 0; i < clusters.size(); i++)
    {
        int x = clusters[i].first;
        int y = clusters[i].second;
        
        int Temp_H = weight(x, y);
        if (Temp_H == INF) continue;
        else H = min(H, Temp_H);
    }
 
    sort(clusters.begin(), clusters.end());
    for (int i = clusters.size() - 1; i >= 0; i--)
    {
        int x = clusters[i].first;
        int y = clusters[i].second;
 
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

bool searchCluster(){
	for(int i = 0 ; i < C ; i++){
		if(map[R - 1][i] == 'x' && !visit[R - 1][i]){
			BFS(R - 1, i);
		}
	}

	bool clusterInAir = false;

	memset(Cluster, false, sizeof(Cluster));

	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			if(map[i][j] == 'x' && !visit[i][j]){
				clusters.push_back(make_pair(i, j));
				Cluster[i][j] = true;
				clusterInAir = true;
			}
		}
	}
	return clusterInAir;
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
        clusters.clear();
        memset(visit, false, sizeof(visit));
        memset(Cluster, false, sizeof(Cluster));
 
        char Order_C;
        int Height = orders[i];
        Height = R - Height;
 
        if (i % 2 == 0) Order_C = 'L';
        else Order_C = 'R';
        
        if (throwStick(Height, Order_C) == false) continue;
    
        if (searchCluster() == false) continue;
        else moveCluster();
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
