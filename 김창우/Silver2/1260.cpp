#include <iostream>
#include <queue>

using namespace std;

int **map; // 좌표
bool* trace; // 흔적 쫓기
int N, M; // 정점 수, 간선 수

queue<int> q;

void dfs(int start) {

    cout << start << " ";
    trace[start] = 1;

    for (int i = 1; i < N + 1; i++) {
        if (map[start][i] && !trace[i]) {
            dfs(i);
        }
    }
}

void bfs(int start) {

    queue<int> q;
    bool* trace = new bool[N + 1]; // 흔적 쫓기
    fill_n(trace, N + 1, false); // 흔적 쫓기 false 초기화
    trace[start] = 1;

    cout << start << " ";

    for (int i = 1; i < N + 1; i++) {
        if (map[start][i] && !trace[i]) {
            q.push(i);
            trace[i] = true;
        }
    }

    while (!q.empty()) {
        int x = q.front();
        cout << q.front() << " ";
        q.pop();

        for (int i = 1; i < N + 1; i++) {
            if (map[x][i] && !trace[i]) {
                q.push(i);
                trace[i] = true;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int V; // 시작 정점

    cin >> N >> M >> V; // 정점 수, 간선 수, 시작 정점 입력받음

    map = new int*[N+1]; // 좌표 동적할당
    trace = new bool[N + 1]; // 흔적 쫓기
    fill_n(trace, N + 1, false); // 흔적 쫓기 false 초기화

    for (int i = 0; i < N+1; i++) { // 좌표 동적할당
        map[i] = new int[N+1];
        fill_n(map[i], N+1, 0);
    }

    for (int i = 0; i < M; i++) { // 좌표계에 값 입력
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    dfs(V);

    cout << "\n";
    fill_n(trace, N + 1, false); // 흔적 쫓기 false 초기화

    bfs(V);

    return 0;
}
