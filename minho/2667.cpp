#include <iostream>
#include <algorithm>

using namespace std;

int N = 0;
int cur = 1;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void sol(int i, int j, int **map,int **check){
    map[i][j] = cur;
    check[i][j] = 1;

    for(int k = 0; k < 4; k++){
        if(i+dx[k] < 0 || i+dx[k] >= N || j+dy[k] < 0 || j + dy[k] >=N){
            continue;
        }
        else if(check[i+dx[k]][j+dy[k]] == 1){
            continue;
        }
        else if(map[i+dx[k]][j+dy[k]] == 1){
            sol(i+dx[k],j+dy[k],map,check);
        }
    }
}

int main()
{
    cin >> N;

    int **map = new int*[N];
    for(int i = 0; i<N;i++){
        map[i] = new int[N];
    }

    int **check = new int*[N];
    for(int i = 0; i<N;i++){
        check[i] = new int[N];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            check[i][j] = 0;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%1d",&map[i][j]);
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 0){
                check[i][j] = 1;
            }
            else if(check[i][j] == 1){
                continue;
            }
            else{
                sol(i,j,map,check);
                cur++;
            }
        }
    }

    int *ans = new int[cur];

    for(int i = 0; i < cur; i++){
        ans[i] = 0;
    }
    ans[0] = cur - 1;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 0){
                continue;
            }
            else{
                ans[map[i][j]]++;
            }
        }
    }

    sort(ans+1,ans+cur);

    for(int i = 0; i < cur; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}