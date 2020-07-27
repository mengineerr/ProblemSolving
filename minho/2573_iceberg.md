# 2573 Iceberg
### How to solve
- 빙산의 분리 여부를 BFS와 전체 빙산의 수를 비교하여 확인
- 빙산의 높이 판정과 그 높이를 감소하는 타이밍은 서로 분리되어야 하므로
- 감소되어야 하는 높이를 저장하는 벡터를 따로 선언

### 분리 여부 및 0 확인
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

### BFS
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

### 높이 탐색 및 감소
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