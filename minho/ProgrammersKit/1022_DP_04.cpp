#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int dp[1000000] = {0,};
    int dp2[1000000] = {0,};
    /*
    현재 idx
    다음 idx + 1
    비교 dp(idx+1) = max(dp(idx) , dp(idx-1) + money(idx+1))
    */
    
    // 첫 집을 턴 경우
    dp[0] = money[0];
    dp[1] = money[0];
    
    for(int i = 2; i < money.size()-1; i++){
        dp[i] = max(dp[i-1], dp[i-2] + money[i]);
    }
    
    // 두번째 집을 턴 경우
    
    dp2[0] = 0;
    dp2[1] = money[1];
    
    for(int i = 2; i < money.size(); i++){
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i]);
    }
    
    answer = max(dp[money.size()-2],dp2[money.size()-1]);
    
    return answer;
}
