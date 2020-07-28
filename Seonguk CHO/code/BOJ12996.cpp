#include <iostream>
#include <cstring>
using namespace std;

int n, a, b, c;

#define MAX 1000000007
long long dp[51][51][51][51];  // a,b,c 노래 곡 수 + 전체노래 수
long long solve(int n1, int n2, int n3, int s){
    if(s==0){
        if(n1 == 0 && n2 == 0 && n3 == 0) return 1;
        return 0;
    }
    if(n1<0||n2<0||n3<0) return 0;
    long long &num = dp[n1][n2][n3][s];
    if(num != -1) return num;
    num = 0;
    num += solve(n1-1, n2, n3, s-1);
    num += solve(n1, n2-1, n3, s-1);
    num += solve(n1, n2, n3-1, s-1);
    num += solve(n1-1, n2-1, n3, s-1);
    num += solve(n1-1, n2, n3-1, s-1);
    num += solve(n1, n2-1, n3-1, s-1);
    num += solve(n1-1, n2-1, n3-1, s-1);
    num %= MAX;
    return num;            
}
int main(){
    cin >> n >> a >> b >> c;
    // 곡은 세 사람중 적어도 한명 부름 (두사람, 세사람 함께 불러도 가능)
    // 녹음해야하는 곡의 수가 주어질때, 앨범을 만들 수 있는 방법의 수
    memset(dp, -1, sizeof(dp));
    cout << solve(a,b,c,n);

    return 0;
}