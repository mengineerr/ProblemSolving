#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct node{
    int node;
    int len;
};

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int *visit = new int[n+1]();
    int *lengths = new int[n+1]();
    vector<int> link[n+1];
    queue<struct node> q;
    int max_len = 0;
    
    for(vector next: edge){
        link[next[0]].push_back(next[1]);
        link[next[1]].push_back(next[0]);
    }
    
    q.push({1,0});
    visit[1] = 1;
    
    while(!q.empty()){
        struct node cur = q.front();
        q.pop();
        
        if(cur.len > max_len)
            max_len = cur.len;
        
        for(int next : link[cur.node]){
            if(visit[next] == 1)
                continue;
            visit[next] = 1;
            lengths[next] = cur.len+1;
            q.push({next, cur.len+1});
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(lengths[i] == max_len)
            answer++;
    }
    
    return answer;
}
