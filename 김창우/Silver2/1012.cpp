#include <iostream>
#include <queue>

using namespace std;

int map[51][51]; // 좌표
int m, n, point; // 가로, 세로, 점의 수

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push(pair<int, int>(x, y));
    map[x][y] = 0;

    while (!q.empty()) {
        int tempX = q.front().first;
        int tempY = q.front().second;
        q.pop();

        if (tempX + 1 >= 0 && tempY >= 0 && tempX + 1 < m && tempY < n && map[tempX + 1][tempY] == 1) {
            map[tempX + 1][tempY] = 0;
            q.push(pair<int, int>(tempX + 1, tempY));
        }
        if (tempX - 1 >= 0 && tempY >= 0 && tempX - 1 < m && tempY < n && map[tempX - 1][tempY] == 1) {
            map[tempX - 1][tempY] = 0;
            q.push(pair<int, int>(tempX - 1, tempY));
        }
        if (tempX >= 0 && tempY + 1 >= 0 && tempX < m && tempY + 1 < n && map[tempX][tempY + 1] == 1) {
            map[tempX][tempY + 1] = 0;
            q.push(pair<int, int>(tempX, tempY + 1));
        }
        if (tempX >= 0 && tempY - 1 >= 0 && tempX < m && tempY - 1 < n && map[tempX][tempY - 1] == 1) {
            map[tempX][tempY - 1] = 0;
            q.push(pair<int, int>(tempX, tempY - 1));
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int testCase; // 테스트 수
    int x, y; // 점 좌표

    cin >> testCase; // 테스트 수 입력받음

    int* count = new int[testCase]; // 테스트별 카운트 저장배열

    for (int k = 0; k < testCase; k++) {
        count[k] = 0;

        cin >> m >> n >> point; // 가로, 세로, 포인트 수 입력받음

        for (int i = 0; i < m; i++) { // 좌표 0으로 초기화
            fill_n(map[i], n, 0);
        }

        for (int i = 0; i < point; i++) { // 해당좌표 1값 대입
            cin >> x >> y;
            map[x][y] = 1;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 1) { // 점이 있을경우 BFS
                    bfs(i, j);
                    count[k]++;
                }
            }
        }
    }

    for (int i = 0; i < testCase; i++) {
        cout << count[i] << "\n";
    }

    return 0;
}
