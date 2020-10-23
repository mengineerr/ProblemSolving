#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int strength[101][101] = {0};
    
    for(vector result: results){
        strength[result[0]][result[1]] = 1;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(strength[j][i] == 1 && strength[i][k] == 1)
                    strength[j][k] = 1;
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        
        for(int j = 1; j <= n; j++)
            if(strength[i][j] == 1 || strength[j][i] == 1)
                cnt++;
        
        if(cnt == n-1)
            answer++;
    }
    
    return answer;
}
