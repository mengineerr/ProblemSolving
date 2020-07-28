# 2206 벽부수고 이동하기
### How to solve
- 부수는 경우와 부수지 않고 동일한 위치를 왔을 때를 구분해야함
- 3차원 배열을 이용하여 두가지 경우를 나눠 적용
- enqueue를 할때 {a,b,c}로 가능
- N, M 이 각각 1인 경우 반례 필요
- 시간의 효율을 위해 BFS를 진행시 1칸 이동과 벽 부수기를 동시에 진행
- memset을 활용한 배열 초기화

### BFS / 두 케이스를 동시 진행함에 유의 / 3차원 배열을 활용한 방법 유의
    int bfs(){
        queue<location> q;
        struct location start;
        start.x = 0;
        start.y = 0;
        start.wall = 0;
        start.distance = 1;
        q.push(start);

        int visit[N][M][2];
        memset(visit,0,sizeof(visit));

        visit[0][0][0] = 1;

        while(!q.empty()){
            struct location cur = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                if(cur.x + dx[i] < 0 || cur.x + dx[i] > M-1 || cur.y + dy[i] < 0 || cur.y + dy[i] > N-1)
                    continue;
                if(map[cur.y + dy[i]][cur.x + dx[i]] == 0 && visit[cur.y + dy[i]][cur.x + dx[i]][cur.wall] == 0){
                    struct location newloc;
                    newloc.x = cur.x + dx[i];
                    newloc.y = cur.y + dy[i];
                    newloc.wall = cur.wall;
                    newloc.distance = cur.distance + 1;
                    visit[newloc.y][newloc.x][newloc.wall] = newloc.distance;
                    if(newloc.y == N-1 && newloc.x == M-1)
                        return newloc.distance;
                    q.push(newloc);
                    
                }
                else if(map[cur.y + dy[i]][cur.x + dx[i]] == 1 && cur.wall == 0 && visit[cur.y + dy[i]][cur.x + dx[i]][cur.wall+1] == 0){
                    struct location newloc;
                    newloc.x = cur.x + dx[i];
                    newloc.y = cur.y + dy[i];
                    newloc.wall = cur.wall + 1;
                    newloc.distance = cur.distance + 1;
                    visit[newloc.y][newloc.x][newloc.wall] = newloc.distance;
                    if(newloc.y == N-1 && newloc.x == M-1)
                        return newloc.distance;
                    q.push(newloc);
                }
            }
        }
        
        return -1;
    }
