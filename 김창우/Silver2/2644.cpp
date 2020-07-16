#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int** map; // 좌표
    int* trace; // 흔적 쫓기
    int n; // 사람수
    int givenA, givenB; // 주어진 사람
    int m; // 관계수
    int result = -1; // 출력값
    queue<int> q; // BFS용 큐 생성

    cin >> n; // 전체사람 수 입력받음
    cin >> givenA >> givenB; // 관계 구해야하는 두 사람 입력받음
    cin >> m; // 관계수 입력받음

    trace = new int[n + 1]; // 흔적 쫓기
    fill_n(trace, n + 1, false); // 흔적 쫓기 false 초기화

    map = new int*[n+1]; // 좌표 동적할당

    for (int i = 0; i < n+1; i++) { // 좌표 동적할당
        map[i] = new int[n+1];
        fill_n(map[i], n+1, 0);
    }

    for (int i = 0; i < m; i++) { // 좌표계에 값 입력
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    q.push(givenA);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 1; i < n + 1; i++) {
            if (map[x][i] == 0 || trace[i] != 0) continue;
            q.push(i);
            trace[i] = trace[x] + 1;
        }
    }

    cout << (trace[givenB] == 0 ? -1 : trace[givenB]);

    return 0;
}
