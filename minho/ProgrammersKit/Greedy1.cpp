#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int cnt = lost.size();
    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());
    
    for(int i = 0; i < lost.size(); i++){
        for(int j = 0; j < reserve.size(); j++){
            if(lost[i] == reserve[j]){
                cnt -= 1;
                reserve[j] = -1;
                lost[i] = -1;
                break;
            }
        }
    }
    
    for(int i = 0; i < lost.size(); i++){
        if(cnt == 0){
            break;
        }
        if(lost[i] == -1)
            continue;
        for(int j = 0; j < reserve.size(); j++){
            if(reserve[j] == -1)
                continue;
            if(lost[i] == reserve[j] -1 || lost[i] == reserve[j] + 1){
                cnt -= 1;
                reserve[j] = -1;
                break;
            }
        }
    }
    
    answer = n - cnt;
    
    return answer;
}
