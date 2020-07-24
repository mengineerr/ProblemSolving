#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0, };
int map[1001][1001];
int dist[1001][1001][2];

struct cord {
	int x;
	int y;
	int en;
};
int n, m;
queue <cord> q;
int ans = 0;
void solve() {
	int x = 0; int y = 0; int en = 0;
	q.push({ x,y,en });
	dist[x][y][en] = 1;
	int nx, ny;
	while (!q.empty()) {
		x = q.front().x; y = q.front().y; en = q.front().en;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i]; ny = y + dy[i];
			if (nx == n - 1 && ny == m - 1) {
				ans = dist[x][y][en] + 1;
				return;
			}
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (map[nx][ny] == 0 && dist[nx][ny][en] == 0) {
					dist[nx][ny][en] = dist[x][y][en] + 1;
					q.push({ nx, ny, en });
				}
				else if (map[nx][ny] != 0 && en == 0 && dist[nx][ny][en + 1] == 0) {
					q.push({ nx, ny, en + 1 });
					dist[nx][ny][en + 1] = dist[x][y][en] + 1;
				}
			
			}
		}

	}
}
int main() {
	cin >> n >> m;
	if (n == 1 && m == 1) {
		cout << 1;
		return 0;
	}
	memset(map, 0, sizeof(map));
	memset(dist, 0, sizeof(dist));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}


	solve();
	if (ans == 0) {
		cout << -1;
	}
	else {
		cout << ans << endl;
	}


	return 0;
}