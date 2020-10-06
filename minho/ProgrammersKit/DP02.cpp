#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int len = triangle.size();
    
    for(int i = len-2; i >= 0; i--){
        for(int j = 0; j < i+1; j++){
            int left = triangle[i][j] + triangle[i+1][j];
            int right = triangle[i][j] + triangle[i+1][j+1];
            
            if(left > right)
                triangle[i][j] = left;
            else
                triangle[i][j] = right;
        }
    }
    
    answer = triangle[0][0];
    
    return answer;
}
