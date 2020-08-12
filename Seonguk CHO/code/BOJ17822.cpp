#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 51

int n, m, t;
int x, d, k;
vector <int> v[MAX];
int chk[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1,-1,0,0};

void rot(){
    for(int i = 1; i*x-1<n;i++){
        if(d == 0){
            for(int j = 0; j < k; j++) rotate(v[i*x-1].begin(), v[i*x-1].begin()+m-1, v[i*x-1].end());
        }else{
            for(int j = 0; j < k; j++) rotate(v[i*x-1].begin(), v[i*x-1].begin()+1, v[i*x-1].end());
        }
    }
}

bool chkAround(int x, int y){
    int nx, ny;
    for(int i = 0; i < 4; i++){
        nx = x + dx[i]; ny = y + dy[i];
        if(nx < 0 || nx == n) continue;
        if(ny < 0) ny = m -1;
        if(ny == m) ny = 0;
        if(v[nx][ny] == v[x][y]) return true; 
    }
    return false;
}
bool adjChk(){
    bool trig = false;
    memset(chk, 0, sizeof(chk));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == 0) continue;
            if(chkAround(i,j)){
                trig = true;
                chk[i][j] = 1;
            }
        }
    }
    return trig;
}
void getAvg(){
    int avg = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == 0) continue;
            avg += v[i][j]; cnt++;
        }
    }
    avg = avg / cnt;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == 0) continue;
            if(v[i][j] > avg){
                v[i][j]--;
            }else if(v[i][j] < avg){
                v[i][j]++;
            }
        }
    } 
}
int main(){
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int temp;
            cin >> temp; 
            v[i].push_back(temp);
        }
    }
    while (t!=0)
    {
        cin >> x >> d >> k;
        t--;
        // 회전 -> 인접 체크 -> 없는 경우 평균치 계산
        rot();
        if(adjChk()){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(chk[i][j] == 1) v[i][j] = 0;
                }
            }
        }else{
            getAvg();
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j< m; j++) ans += v[i][j];
    }
    cout << ans;
    return 0;
}