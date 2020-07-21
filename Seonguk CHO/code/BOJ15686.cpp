#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
#define MAX 51
int n, m;
int map[MAX][MAX];
int dist[2*MAX];
struct loc{
    int x, y;
};
vector <loc> h; // house
vector <loc> c; // chicken

int main(){
    cin >> n >> m;
    int cnt = 0;
    memset(map,0,sizeof(map));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) h.push_back({i,j});
            if(map[i][j] == 2){
                cnt++; c.push_back({i,j});
            } 
        }
    }
    vector <int> set;
    int ans = 1000000;
    for(int i = 0; i < m; i++) set.push_back(1);
    for(int i = 0; i < cnt-m; i++) set.push_back(0);
    do{
        // 치킨집 선택 -> 모든 집 최소 거리 계산 

        memset(dist, 1000000, sizeof(dist));
        int x, y, cx, cy;
        int d1, d2;
        for(int i = 0; i < h.size(); i++){
            x = h[i].x; y = h[i].y;
            for(int j = 0; j < c.size(); j++){
                if(set[j] == 0) continue;
                cx = c[j].x; cy = c[j].y;
                d1 = (x-cx > 0) ? x-cx : -1*(x-cx);
                d2 = (y-cy>0)? y-cy : -1*(y-cy);
                dist[i] = (d1+d2 < dist[i]) ? d1+d2 : dist[i];
            }
        }   
        int temp = 0; 
        for(int i = 0; i < h.size(); i++){
            temp += dist[i];
        }
        ans = (temp < ans) ? temp : ans;
    }while(prev_permutation(set.begin(), set.end()));

    cout << ans;
    return 0;
}