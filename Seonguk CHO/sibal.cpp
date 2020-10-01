#include <iostream>
#include <cstring>

using namespace std;

int map[6][4][2];
int copyMap[6][4];
int chkMap[4][4];
int t, x, y;
int ans = 0;

int getDist(int x, int y, int which){
    int dist = 1;
    int nx;
    while (true){
        nx = x + dist;
        if(nx > 5) break;
        if(map[nx][y][which] != 0) break;
        dist++;
    }
    return dist -1;
}
void putBlock(){
    int dist;
    switch (t){
    case 1:
        dist = getDist(0,y,0);
        map[dist][y][0] = 1;
        dist = getDist(0,3-x,1);
        map[dist][3-x][1] = 1;
        break;
    case 2:
        // 가로 블럭
        dist = min(getDist(0,y,0), getDist(0,y+1,0));
        map[dist][y][0] = 2; map[dist][y+1][0] = 2;
        dist = getDist(0,3-x,1);
        map[dist][3-x][1] = 3; map[dist-1][3-x][1] = 3;
        break;
    case 3:
        dist = getDist(0,y,0);
        map[dist][y][0] = 3; map[dist-1][y][0] = 3;
        dist = min(getDist(0,3-x,1), getDist(0,2-x,1));
        map[dist][3-x][1] = 2; map[dist][2-x][1] = 2;
        break;
    }
}
void chkBlock(){
    int cnt = 0; bool flag= false;
    int dist = 0;
    for(int h = 0; h < 2; h++){
        while (true){
            flag = false;
            for(int i = 5; i >= 0; i--){
                cnt = 0;
                for(int j = 0; j < 4; j++){
                    if(map[i][j][h] != 0) cnt++;
                }
                if(cnt == 4){
                    for(int j = 0; j < 4; j++) map[i][j][h] =0;
                    ans++; flag = true;
                }
            }
            if(flag){
                memset(chkMap,0,sizeof(chkMap));
                for(int i = 5; i >= 0; i--){
                    for(int j = 0; j < 4; j++){
                        if(map[i][j][h] != 0){
                            switch (map[i][j][h])
                            {
                            case 1:
                                if(chkMap[i][j] == 1) break;
                                dist = getDist(i,j,h);
                                map[i][j][h] = 0; map[i+dist][j][h] = 1; chkMap[i][j] = 1;
                                break;
                            case 2:
                                if(chkMap[i][j] == 1) break;
                                dist = min(getDist(i,j,h), getDist(i,j+1,h));
                                map[i][j][h] = 0; map[i][j+1][h] = 0;
                                map[i+dist][j][h] = 2; map[i+dist][j+1][h] = 2;
                                chkMap[i][j] = 1; chkMap[i][j+1] = 1;
                                break;
                            case 3:
                                if(chkMap[i][j] == 1) break;
                                dist = getDist(i,j,h);
                                if(map[i-1][j][h] != 3){
                                    map[i][j][h] = 0; map[i+dist][j][h] = 3;
                                    chkMap[i][j] = 1;
                                }else{
                                    map[i][j][h] = 0; map[i-1][j][h] = 0;
                                    chkMap[i][j] = 1; chkMap[i-1][j] = 1;
                                    map[i+dist][j][h] = 3; map[i+dist-1][j][h] = 3;
                                }
                                break;
                            }
                        }   
                    }
                }                
            }
            if(!flag) break;
        }
    }
}
void getCopy(int x, int which){
    for(int i = x; i < x + 4; i++){
        for(int j = 0; j < 4; j++){
            copyMap[i-x][j] = map[i][j][which];
        }
    }
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 4; j++) map[i][j][which] = 0;
    }
    for(int i = 2; i < 6; i++){
        for(int j = 0; j < 4; j++) map[i][j][which] = copyMap[i-2][j];
    }
}
void shiftBlock(){
    bool trig = false;
    for(int h = 0; h < 2; h++){
        trig = false;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 4; j++){
                if(map[i][j][h] != 0){
                    trig = true;
                    getCopy(i,h);
                }
                if(trig) break;
            }
            if(trig) break;
        }
    }
}
int getNum(){
    int num = 0;
    for(int h = 0; h < 2; h++){
        for(int i = 2; i < 6; i++){
            for(int j = 0; j < 4; j++) if(map[i][j][h] != 0) num++;
        }
    }
    return num;
}
int main(){
    memset(map, 0, sizeof(map));
    int rep;
    cin >> rep;
    for(int i = 0; i < rep; i++){
        cin >> t >> x >> y; 
        putBlock();
        chkBlock();
        shiftBlock();
    }
    int a = getNum();
    cout << ans << endl << a;
    return 0;
}
