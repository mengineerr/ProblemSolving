#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;
int **map;
int ice = 0;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

struct location
{
    int x;
    int y;
};


int check(struct location ice){
    int loc[N][M];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            loc[i][j] = 0;

    queue<location> q;

    loc[ice.y][ice.x] = 1;
    q.push(ice);
    int ans = 1;

    while(!q.empty()){
        struct location cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            if(cur.y + dy[i] < 0 || cur.y + dy[i] > N-1 || cur.x + dx[i] < 0 || cur.x + dx[i] > M-1)
                continue;
            if(loc[cur.y+dy[i]][cur.x+dx[i]] == 1)
                continue;
            if(map[cur.y+dy[i]][cur.x+dx[i]] == 0)
                continue;
            
            struct location newloc;
            newloc.y = cur.y + dy[i];
            newloc.x = cur.x + dx[i];
            q.push(newloc);
            loc[cur.y+dy[i]][cur.x+dx[i]] = 1;
            ans++;
        }
    }

    return ans;
}

int main()
{
    cin >> N >> M;

    vector<location> ice;

    map = new int*[N];
    for(int i = 0; i < N; i++)
        map[i] = new int[M];
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] > 0){
                struct location temp;
                temp.y = i;
                temp.x = j;
                ice.push_back(temp);
            }
        }
            

    int time = 0;
    bool flag = false;

    while(1){
        int total = 0;
        int idx = 0;

        for(int i = 0; i < ice.size(); i++){
            if(map[ice[i].y][ice[i].x] > 0){
                total++;
                idx = i;
            }
        }

        if(total == 0){
            time = 0;
            break;
        }

        if(check(ice[idx]) < total){ // 두 덩어리로 나뉘면
            break;
        }

        int variation[ice.size()] = {0,};

        // 감소 높이 탐색
        for(int i = 0; i < ice.size(); i++){
            int cnt = 0;
            int curx = ice[i].x;
            int cury = ice[i].y;

            if(map[cury][curx] == 0)    // 빙산이 없는 경우
                continue;

            for(int j = 0; j < 4; j++){ // 바다 영역 찾기
                if(curx + dx[j] < 0 || curx + dx[j] > M-1 || cury + dy[j] < 0 || cury + dy[j] > N-1)
                    continue;
                if(map[cury + dy[j]][curx + dx[j]] == 0)
                    cnt++;
            }

            variation[i] = cnt;
        }

        // 높이 제거
        for(int i = 0; i < ice.size();i++){
            if(variation[i] > 0)
                map[ice[i].y][ice[i].x] -= variation[i];
            
            if(map[ice[i].y][ice[i].x] < 0)
                map[ice[i].y][ice[i].x] = 0;
        }

        time++;
    }

    cout << time << "\n";
    
    return 0;
}