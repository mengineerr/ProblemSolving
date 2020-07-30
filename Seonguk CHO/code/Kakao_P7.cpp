#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

vector <vector<int>> board;

#define MAX 101
int n;

struct coord{
    int hx,hy,tx,ty;
};
struct dat{
    int x,y,dir,dist;
};

coord getCoord(int x, int y, int dir){
    coord s;
    if(dir == 0){
        s.hx = x; s.hy = y; s.tx = x; s.ty = y-1;
    }else if(dir == 1){
        s.hx = x; s.hy = y; s.tx = x+1; s.ty = y;
    }
    return s;
}
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1,-1,0,0};
bool isAns(coord s){
    if(s.hx == n-1 && s.hy == n-1) return true;
    if(s.tx == n-1 && s.ty == n-1) return true;
    return false;
}
bool chk(int x, int y, vector<vector<int>> &board){
    if(x<0||x>=n||y<0||y>=n) return false;
    if(board[x][y] == 1) return false;
    return true;
}
int bfs(vector<vector<int>> &board){
    int ans = 1000000;
    int visit[MAX][MAX][2];
    memset(visit, 0, sizeof(visit));
    int x,y,nx,ny,dir,dist;
    queue <dat> q;
    q.push({0,1,0,0});
    visit[0][1][0] = 1;

    while(!q.empty()){
        x = q.front().x; y = q.front().y; dir = q.front().dir; dist = q.front().dist;
        q.pop();
        coord now = getCoord(x,y,dir);
        if(isAns(now)){
            // 답 업데이트
            ans = (dist < ans) ? dist : ans;
        }
        for(int i = 0; i < 4; i++){
            nx = x + dx[i]; ny = y + dy[i];
            coord next = getCoord(nx,ny,dir);
            if(chk(next.hx,next.hy,board)&&chk(next.tx,next.ty,board)){
                if(visit[next.hx][next.hy][dir] == 1) continue;
                visit[next.hx][next.hy][dir] = 1;
                q.push({next.hx,next.hy,dir,dist+1});
            }
        }
        if(dir == 0){
            // 누워있는 경우 회전
            if(chk(now.hx-1,now.hy,board) && chk(now.hx-1,now.hy-1,board)){
                if(visit[now.hx-1][now.hy-1][1] == 0){
                    visit[now.hx-1][now.hy-1][1] = 1;
                    q.push({now.hx-1,now.hy-1,1,dist+1});  
                }       
                if(visit[now.hx-1][now.hy][1] == 0){
                    visit[now.hx-1][now.hy][1] = 1;
                    q.push({now.hx-1,now.hy,1,dist+1});
                } 
            }
            if(chk(now.hx+1,now.hy,board)&&chk(now.hx+1,now.hy-1,board)){
                if(visit[now.hx][now.hy-1][1] == 0){
                    visit[now.hx][now.hy-1][1] = 1;
                    q.push({now.hx,now.hy-1,1,dist+1});
                }  
                if(visit[now.hx][now.hy][1] == 0){
                    visit[now.hx][now.hy][1] = 1;
                    q.push({now.hx,now.hy,1,dist+1});
                }            
            }
        }else if(dir == 1){
            // 서있는 경우 회전
            if(chk(now.hx,now.hy-1,board)&&chk(now.hx+1,now.hy-1,board)){
                if(visit[now.hx][now.hy][0] == 0){
                    visit[now.hx][now.hy][0] = 1;
                    q.push({now.hx,now.hy,0,dist+1});
                }
                if(visit[now.hx+1][now.hy][0] == 0){
                    visit[now.hx+1][now.hy][0] = 1; 
                    q.push({now.hx+1, now.hy, 0, dist+1});
                }
            }
            if(chk(now.hx,now.hy+1,board)&&chk(now.hx+1,now.hy+1,board)){
                if(visit[now.hx][now.hy+1][0] == 0){
                    visit[now.hx][now.hy+1][0] = 1;
                    q.push({now.hx,now.hy+1,0,dist+1});
                }
                if(visit[now.hx+1][now.hy+1][0] == 0){
                    visit[now.hx+1][now.hy+1][0] = 1;
                    q.push({now.hx+1,now.hy+1,0,dist+1});
                }
            }
        }
    }

    return ans;
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    n = board.size();
    answer = bfs(board);
    return answer;
}
