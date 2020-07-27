#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 11
int n;
vector <int> v[MAX];
int num[MAX];
int ans = 1000000;

struct dat{
    int len, val;
};
dat bfs(vector <int> &set, int which){
    dat a;
    int start, now, nx;
    for(int i = 0; i < set.size(); i++){
        if(set[i] == which){
            start = i; break;
        }
    }
    int visit[MAX] = {0,};
    a.len = 1; a.val = num[start]; visit[start] = 1;
    queue <int> q;
    q.push(start);
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        for(int next: v[now]){
            if(set[next] == which && visit[next] == 0){
                q.push(next); visit[next] = 1; a.len++; a.val += num[next];
            }
        }
    }
    return a;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    int a,b;
    for(int i = 0; i < n ; i++){
        cin >> a;
        for(int j = 0; j < a; j++){
            cin >> b;
            v[i].push_back(b-1);
        }
    }
    // 1. 두 팀 개수 설정
    // 2. 순열을 통한 두 팀 세팅
    // 3. 세팅 후 bfs로 팀 확인, 값 비교
    for(int i = 1; i <= n/2; i++){
        vector <int> set;
        for(int i = 0; i < n; i++) set.push_back(0);
        for(int j = 0; j < i; j++){
            set[j] = 1;
        }
        int lenA = i; int lenB = n-i;
        // i - A팀개수 , n-i - B 팀 개수
        do{
            dat teamA = bfs(set,1);
            dat teamB = bfs(set,0);
            if(teamA.len == lenA && teamB.len == lenB){
                int temp;
                temp = (teamA.val - teamB.val >= 0) ? teamA.val - teamB.val : -1*(teamA.val - teamB.val);
                ans = (temp < ans) ? temp : ans;
            }
        }while(prev_permutation(set.begin(), set.end()));
    }
    if(ans == 1000000){
        cout << -1;
    }else{
        cout << ans;
    }
    return 0;
}