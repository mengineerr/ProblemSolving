#include <iostream>
#include <algorithm>

int map[25][25] = {0,};
int check[25][25] = {0,};

//함수에 2차원 배열을 넘겨주려면 가로 크기값이 미리 정해져야 한다
void find(int i, int j, int N,int num){
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    if(check[i][j] == 1){
        return;
    }
    else{
        check[i][j] = 1;
        map[i][j] = num;
    }

    for(int k = 0; k < 4; k++){
        int temp_i = i+dx[k];
        int temp_j = j+dy[k];
        
        if(temp_i < 0 || temp_i >= N || temp_j < 0 || temp_j >= N){
            continue;
        }
        else if(map[temp_i][temp_j] == 1 && check[temp_i][temp_j] == 0){
            find(temp_i,temp_j,N,num);
        }
    }
}

int main()
{
    int N = 0;
    std::cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <N; j++){
            scanf("%1d",&map[i][j]);
        }
    }

    int num = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <N; j++){
            if(map[i][j]==1 && check[i][j] == 0){
                num++;
                find(i,j,N,num);
            }
        }
    }

    std::cout << num << "\n";

    
    int *output =  new int[num];

    for(int i = 0; i < N; i++){
        for(int j = 0; j <N; j++){
            if(map[i][j]>=1){
                output[map[i][j]-1]++;
            }
        }
    }

    std::sort(output, output+num);

    for(int i = 0; i<num ; i++) {
        std::cout << output[i] << "\n";
    }
}