# 19236 Young Shark
### How to solve
- 전형적인 시뮬레이션 스타일
- 재귀함수를 이용하여 각 케이스를 나눠 적용
- 각 재귀마다 새로운 지도를 형성하도록 물고기 배열 구조체를 넘겨준다
- 물고기의 생사는 dir이 -1인 경우 죽은것으로 고려
- 상어의 후보 영역을 벡터에 저장하고 각 후보마다 재귀함수 적용
- 변수가 다양한 영역에서 사용되므로 잘못 변경되지 않도록 주의!

### 재귀함수의 지도 영역 재설정 및 상어 잡아먹기
    location fish[17];
    int map_temp[4][4];
    memset(map_temp,0,sizeof(map_temp));

    for(int i = 1; i <= 16; i++){
        fish[i] = before[i];    // 물고기 위치 새로 저장
        if(fish[i].dir != -1)
            map_temp[fish[i].y][fish[i].x] = i; // 살아있는 물고기위치 설정
    }

    // 잡아먹기
    fish[map_temp[shark.y][shark.x]].dir = -1;
    map_temp[shark.y][shark.x] = -1;    // 상어 위치

### 물고기 이동 / 빈공간인 경우와 아닌경우 따로 설정
    for(int i = 1; i <= 16; i++){
        if(fish[i].dir == -1)
            continue;
        int curx = fish[i].x; int cury = fish[i].y;
        int cnt = 0;
        while(1){
            if(cnt > 8)
                break;
            
            int newx = curx + dx[fish[i].dir];
            int newy = cury + dy[fish[i].dir];

            cnt++;

            if(newx < 0 || newx > 3 || newy < 0 || newy > 3){
                fish[i].dir++;
                if(fish[i].dir > 7)
                    fish[i].dir -= 8;
                continue;
            }
                
            if(map_temp[newy][newx] == -1){
                fish[i].dir++;
                if(fish[i].dir > 7)
                    fish[i].dir -= 8;
                continue;
            }

            int num_temp = map_temp[newy][newx];

            if(num_temp == 0){
                map_temp[newy][newx] = i;
                map_temp[cury][curx] = num_temp;
                fish[i].x = newx;
                fish[i].y = newy;
            }
            else{
                map_temp[newy][newx] = i;
                map_temp[cury][curx] = num_temp;
                fish[num_temp].x = curx;
                fish[num_temp].y = cury;
                fish[i].x = newx;
                fish[i].y = newy;
            }
            break;
        }     
    }

### 상어 후보 선정 및 재귀함수
    vector<location> candidates;
    int curx = shark.x;
    int cury = shark.y;
    int curdir = shark.dir;
    while(1){
        curx += dx[curdir];
        cury += dy[curdir];
        if(curx < 0 || curx > 3 || cury < 0 || cury > 3)
            break;
        if(map_temp[cury][curx] == 0)
            continue;
        candidates.push_back({curx,cury,curdir});
    }

    if(candidates.size() == 0 && ans < total){
        ans = total;
    }

    for(int i = 0; i < candidates.size(); i++){
        int x = candidates[i].x;
        int y = candidates[i].y;
        int number = map_temp[y][x];
        candidates[i].dir = fish[number].dir;
        //fish[number].dir = -1;
        search(fish,candidates[i],total+number);
    }