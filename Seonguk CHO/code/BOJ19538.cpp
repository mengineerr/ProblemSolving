#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 200001
int n, m;
struct dat{
    int now, t;
};
queue <dat> q;
vector <int> v[10];
int ans[10] = {-1,};
void bfs(){
    int now, nx, t, cnt;
    while (!q.empty()){
        now = q.front().now; t= q.front().t;
        q.pop();
        for(int next : v[now]){
            if(ans[next] == -1){
                cnt = 0;
                for(int adj : v[next]){
                    if(ans[adj] != -1 && ans[adj] <= t) cnt++;
                }
                if(2*cnt >= v[next].size()){
                    q.push({next, t+1});
                    ans[next] = t+1;
                }
            }
        }
    }
}
int main(){
    cin >> n;
    int num;
    for(int i = 0; i < n; i++){
        while (true){
            cin >> num;
            if(!num) break;
            v[i].push_back(num-1);
        }
    }
    cin >> m;
    memset(ans, -1, sizeof(ans));
    for(int i = 0; i < m; i++){
        cin >> num;
        ans[num-1] = 0;
        q.push({num-1,0});
    }
    bfs();
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    return 0;
}