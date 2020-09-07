#include <string>
#include <vector>
#include <iostream>
#include <queue>
#define MAX 25

using namespace std;
int row = 0;
int col = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct loc {
    int y; int x; int dir; int price;
};


int solution(vector<vector<int>> board) {
    int answer = 0;
    answer = 987654321;
    row = board.size();
    
    queue<loc> q;
    q.push({0,0,-1,0});
    board[0][0] = 1;
    
    while(!q.empty()){
        loc cur = q.front();
        q.pop();
        
        if(cur.y == row-1 && cur.x == row-1)
            answer = min(answer, cur.price);
        
        for(int i = 0; i < 4; i++){
            if(cur.y + dy[i] < 0 || cur.y + dy[i] > row-1 || cur.x + dx[i] < 0 || cur.x + dx[i] > row-1)
                continue;
            if(board[cur.y + dy[i]][cur.x+dx[i]] == 1)
                continue;
            
            int new_price = 0;
            if(cur.dir == i || cur.dir == -1)
                new_price = cur.price + 100;
            else
                new_price = cur.price + 600;
            
            if(board[cur.y + dy[i]][cur.x+dx[i]] == 0 || board[cur.y + dy[i]][cur.x+dx[i]] >= new_price){
                board[cur.y + dy[i]][cur.x+dx[i]] = new_price;
                q.push({cur.y + dy[i], cur.x+dx[i], i, new_price});
            }
        }
    }
    
    return answer;
}
