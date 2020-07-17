#include <iostream>

using namespace std;

struct scent {
    int shark;
    int time;
};

int main()
{
    int N,M,k;
    cin >> N >> M >> k;

    // Array of structure
    struct scent s[N][N];
    
    // For 0 initialization
    for(int i =0; i < N; i++)
        for(int j = 0; j <N; j++)
            s[i][j] = {};
        
    int move[M][4];


    
    
    return 0;
}