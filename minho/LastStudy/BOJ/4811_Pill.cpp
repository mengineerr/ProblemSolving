#include <iostream>
#include <vector>

using namespace std;

vector<long long> result;
long long pill[31][31];

long long dp(int W, int H)
{
    // If There is no flawless pill, ans doesn't change anymore
    if(W < 0){
        return 0;
    }

    // If There is no pill, ans is 1
    if(W == 0 && H == 0){
        return 1;
    }

    if(pill[W][H] > 0){
        return pill[W][H];
    }

    if(W > 0){
        pill[W][H] += dp(W-1,H+1);
    }

    if(H > 0){
        pill[W][H] += dp(W,H-1);
    }

    return pill[W][H];
}

int main()
{
    int N = 0;
    result.clear();

    while(1){
        cin >> N;

        if( N == 0 ){
            break;
        }

        result.push_back(dp(N,0));
    }

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << "\n";
    }
}