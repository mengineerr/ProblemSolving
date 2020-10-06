#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int answer = 9;
int Num = 0;
int Target = 0;

void dfs(int cur, int cnt){
    if(cnt >= 9)
        return;
    
    if(cur == Target){
        answer = min(answer,cnt);
        return;
    }
    
    int tmp = 0;
    
    for(int i = 0; i + cnt < 9; i++){
        tmp = tmp * 10 + Num;
        
        dfs(cur+tmp, cnt+1+i);
        dfs(cur-tmp, cnt+1+i);
        dfs(cur*tmp, cnt+1+i);
        dfs(cur/tmp, cnt+1+i);
    }
}

int solution(int N, int number) {
    Num = N;
    Target = number;
    
    dfs(0,0);
    
    if(answer >= 9) // failed case
        return -1;
    
    return answer;
}
