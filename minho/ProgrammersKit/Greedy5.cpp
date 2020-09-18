/*
    알고리즘 복습
    - Kruskal MST 알고리즘
    - Union-find
*/ 

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> parent;

int getParent(int x){
    if(parent[x] == x)
        return x;
    else
        return parent[x] = getParent(parent[x]);
}

int find(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a == b)
        return 1;
    else
        return 0;
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

bool compare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), compare);
    
    for(int i = 0; i < n; i++)
        parent.push_back(i);
    
    for(auto next: costs){
        if(!find(next[0],next[1])){
            answer += next[2];
            unionParent(next[0],next[1]);
        }
    }
    
    return answer;
}
