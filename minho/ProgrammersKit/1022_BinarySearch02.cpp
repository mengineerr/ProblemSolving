#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    rocks.push_back(distance);
    sort(rocks.begin(),rocks.end());
    
    int left = 1;
    int right = distance;
    
    while(left <= right){
        int mid = (left + right) / 2;
        int idx = 0;
        int cnt = 0;
        
        for(int next : rocks){
            if(mid > next - idx)
                cnt++;
            else
                idx = next; // 연속된 돌의 거리가 mid보다 작은 경우 포함
        }
        
        if(cnt > n)
            right = mid - 1;
        else{
            left = mid + 1;
            answer = max(answer, mid);
        }
    }
    
    return answer;
}
