#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int dx[8] = {0 ,-1,-1,-1,0,1,1, 1};
int dy[8] = {-1,-1, 0, 1,1,1,0,-1};
int ans = 0;
int map[4][4];

struct location {
    int x;
    int y;
    int dir;
};

void search(location before[],location shark, int total){
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
}

int main()
{
    location fish[17];

    int num,dir;

    for(int i = 0; i < 16; i++){
        cin >> num >> dir;
        map[i/4][i%4] = num;
        fish[num] = {i%4,i/4,dir-1};
    }

    location shark = {0,0,0};

    int kill = map[0][0];

    shark.dir = fish[kill].dir;
    fish[kill].dir = -1;    // 죽으면 방향을 -1로

    search(fish,shark,kill);

    cout << ans << "\n";

    return 0;
}