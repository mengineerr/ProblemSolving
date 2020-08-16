#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define MAX 100

using namespace std;
int R = 0, C = 0, N= 0;
char map[MAX][MAX];
bool broken = false;
bool visit[MAX][MAX];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int total = 0;

struct loc {
    int y; int x;
};

int bfs(int idx){
    int ans = 1;
    queue<loc> q;
    q.push({R-1,idx});
    visit[R-1][idx] = true;

    while(!q.empty()){
        loc cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            if(cur.x + dx[i] < 0 || cur.x + dx[i] > C-1 || cur.y + dy[i] < 0 || cur.y + dy[i] > R-1)
                continue;
            if(map[cur.y+dy[i]][cur.x+dx[i]] == '.') continue;
            if(visit[cur.y+dy[i]][cur.x+dx[i]] == true) continue;

            visit[cur.y+dy[i]][cur.x+dx[i]] = true;
            ans++;
            q.push({cur.y+dy[i],cur.x+dx[i]});
        }
    }

    return ans;
}

// 클러스터 움직임 여부 판단 및 이동
void Move(){
    // bfs로 판단
    // total 미네랄수와 비교
    int cnt = 0;
    memset(visit,false,sizeof(visit));

    // 클러스터 움직임 판단
    for(int i = 0; i < C; i++){
        if(visit[R-1][i] == true) continue;
        if(map[R-1][i] == '.') continue;

        cnt += bfs(i);
    }

    if(cnt != total){   // 움직일 클러스터가 존재
        vector<loc> v;   // 움직여야할 클러스터 모음 
        for(int i = R-1; i >= 0; i--){
            for(int j = 0; j < C; j++){
                if(map[i][j] == '.') continue;
                if(visit[i][j] == true) continue;
                v.push_back({i,j});
                map[i][j] = '.';
            }
        }
        int low = 1;
        while(1){
            bool flag = true;
            for(loc next : v){
                if(visit[next.y+low][next.x] == true || next.y+low > R-1){
                    flag = false;
                    break;
                }
            } 
            if(flag == false)
                break;
                
            low++;
        }
        
        for(loc next : v) 
            map[next.y+low-1][next.x] = 'x';
    }
}

// 미네랄 파괴 함수
void breakMineral(int dir, int height){
    if(dir == 0){
        for(int i = 0; i < C; i++){
            if(map[height][i] == 'x'){
                map[height][i] = '.';
                total--;
                broken = true;
                return;
            }
        }
    }
    else if(dir == 1){
        for(int i = C-1; i >= 0; i--){
            if(map[height][i] == 'x'){
                map[height][i] = '.';
                total--;
                broken = true;
                return;
            }
        }
    }
}

int main()
{
    cin >> R >> C;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++){
            cin >> map[i][j];
            if(map[i][j] == 'x') total++;
        }
    
    cin >> N;

    for(int i = 0; i < N; i++){
        int dir = i % 2;
        int height = 0;
        cin >> height;
        height = R - height;
        broken = false; // 미네랄 파괴 여부 판별
        breakMineral(dir,height);   // 막대기
        
        // 미네랄이 파괴되면
        if(broken == true) Move();
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << map[i][j];
        }
        cout << "\n";
    }

    return 0;
}