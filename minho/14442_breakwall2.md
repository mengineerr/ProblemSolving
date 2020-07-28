# 14442 벽부수고 이동하기2
### How to solve
- 기본적으로 2206번과 동일
- 부술수 있는 벽의 개수를 고려하여 해당 벽의 개수까지만 이동 처리

### BFS
    if(map[cur.y + dy[i]][cur.x + dx[i]] == 0 && dist[cur.y + dy[i]][cur.x + dx[i]][cur.wall] == 0){
        dist[cur.y + dy[i]][cur.x + dx[i]][cur.wall] = dist[cur.y][cur.x][cur.wall] + 1;
        q.push({cur.x + dx[i],cur.y + dy[i],cur.wall});
    }
    else if(cur.wall < K && map[cur.y + dy[i]][cur.x + dx[i]] == 1 && dist[cur.y + dy[i]][cur.x + dx[i]][cur.wall] == 0){
        dist[cur.y + dy[i]][cur.x + dx[i]][cur.wall + 1] = dist[cur.y][cur.x][cur.wall] + 1;
        q.push({cur.x + dx[i],cur.y + dy[i],cur.wall + 1});
    }