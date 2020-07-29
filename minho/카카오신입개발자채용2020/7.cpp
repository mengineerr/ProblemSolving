#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[5] = {100,1,0,-1,0}; // index는 1부터 4까지
int dy[5] = {100,0,1,0,-1};
int N, M;

struct drone {
    int y; int x; int dir; int time;
};

int solution(vector<vector<int>> board) {
    int answer = 0;

    N = board.size();
    M = board[0].size();

    int visit[N][M][5];
    memset(visit,0,sizeof(visit));

    queue<drone> q;
    q.push({0,0,1,0});
    visit[0][0][0] = 1;
    visit[0][0][1] = 1;

    while(!q.empty()){
        struct drone cur = q.front();
        q.pop();

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(i == cur.y && j == cur.x){
                    cout << 2;
                }
                else if(i == cur.y + dy[cur.dir] && j == cur.x + dx[cur.dir]){
                    cout << 2;
                }
                else
                    cout << board[i][j];
            }
            cout << "\n";
        }
        cout << "\n";

        if(cur.x == M-1 && cur.y == N-1){
            answer = cur.time;
            break;
        }
        if(cur.x + dx[cur.dir] == M-1 && cur.y + dy[cur.dir] == N-1){
            answer = cur.time;
            break;
        }

        // 드론 이동
        for(int i = 1; i <= 4; i++){
            int Ax = cur.x + dx[i];
            int Ay = cur.y + dy[i];
            int Bx = cur.x + dx[cur.dir] + dx[i];
            int By = cur.y + dy[cur.dir] + dy[i];

            if(Ax < 0 || Ax > M-1 || Ay < 0 || Ay > N-1 || Bx < 0 || Bx > M-1 || By < 0 || By > M-1)
                continue;

            if(board[Ay][Ax] == 1 || board[By][Bx] == 1)
                continue;
            if(visit[Ay][Ax][cur.dir] == 1)
                continue;

            bool flag = true;
            
            switch(cur.dir){
                case 1 : 
                    if(visit[By][Bx][3] == 1)
                        flag = false;
                    break;
                case 2 : 
                    if(visit[By][Bx][4] == 1)
                        flag = false;
                    break;
                case 3 : 
                    if(visit[By][Bx][1] == 1)
                        flag = false;
                    break;
                case 4 : 
                    if(visit[By][Bx][2] == 1)
                        flag = false;
                    break;
                default:
                    break;
            }

            if(flag == false)
                continue;
            
            visit[Ay][Ax][cur.dir] = 1;
            q.push({Ay,Ax,cur.dir,cur.time+1});
        }

        // 드론 회전이동
        int Ax = cur.x;
        int Ay = cur.y;
        int Bx = cur.x + dx[cur.dir];
        int By = cur.y + dy[cur.dir];

        if(cur.dir == 1 || cur.dir == 3){   // 가로 기준
            if(Ay+1 < N){
                if(board[Ay+1][Ax] == 0 && board[Ay+1][Bx] == 0){   // 아래
                    if(visit[Ay][Ax][2] == 0 && visit[Ay+1][Ax][4] == 0){
                        visit[Ay][Ax][2] = 1;
                        q.push({Ay,Ax,2,cur.time+1});
                    }
                    if(visit[Ay+1][Bx][4] == 0 && visit[By][Bx][2] == 0){
                        visit[Ay+1][Bx][4] = 1;
                        q.push({Ay+1,Bx,4,cur.time+1});
                    }
                }
            }
            if(Ay-1 >= 0){
                if(board[Ay-1][Ax] == 0 && board[Ay-1][Bx] == 0){   // 위
                    if(visit[Ay][Ax][4] == 0 && visit[Ay-1][Ax][2] == 0){
                        visit[Ay][Ax][4] = 1;
                        q.push({Ay,Ax,4,cur.time+1});
                    }
                    if(visit[Ay-1][Bx][2] == 0 && visit[By][Bx][4] == 0){
                        visit[Ay-1][Bx][2] = 1;
                        q.push({Ay-1,Bx,2,cur.time+1});
                    }
                }
            }
        }
        else{   //세로 기준
            if(Ax + 1 < M){
                if(board[Ay][Ax+1] == 0 && board[By][Ax+1] == 0){   // 오른쪽
                    if(visit[Ay][Ax][1] == 0 && visit[Ay][Ax+1][3] == 0){
                        visit[Ay][Ax][1] = 1;
                        q.push({Ay,Ax,1,cur.time+1});
                    }
                    if(visit[By][Ax+1][3] == 0 && visit[By][Bx][1] == 0){
                        visit[By][Ax+1][3] = 1;
                        q.push({By,Ax+1,3,cur.time+1});
                    }
                }
            }
            if(Ax -1 >= 0){
                if(board[Ay][Ax-1] == 0 && board[By][Ax-1] == 0){
                    if(visit[Ay][Ax][3] == 0 && visit[Ay][Ax-1][1] == 0){
                        visit[Ay][Ax][3] = 1;
                        q.push({Ay,Ax,3,cur.time+1});
                    }
                    if(visit[By][Ax-1][1] == 0 && visit[By][Bx][3] == 0){
                        visit[By][Ax-1][1] = 1;
                        q.push({By,Ax-1,1,cur.time+1});
                    }
                }
            }
        }

        //answer++;
    }

    return answer;
}

int main()
{
    vector<vector<int>> input(5);

    int temp = 0;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> temp;
            input[i].push_back(temp);
        }
    }

    cout << solution(input) << "\n";

    return 0;
}