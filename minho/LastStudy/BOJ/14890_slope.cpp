#include <iostream>
#include <cstdio>
#define MAX 100

int map[MAX][MAX] = {0,};
int cnt = 0;
int N, M = 0;

void rowTravel(int row)
{
    // check : Slide location
    bool check[N];
    for(int i = 0 ; i < N; i++){
        check[i] = false;
    }

    for(int i = 0 ; i < N-1 ; i++){
        if(abs(map[row][i] - map[row][i+1]) > 1){
            return;
        }
        else if((map[row][i] - map[row][i+1]) == 1){
            // Check Slide
            if(i + M > N-1){
                return;
            }

            if(M == 1){
                check[i+1] = true;
            }
            else{
                for(int j = 1; j < M; j++){
                    if(map[row][i+1] == map[row][i+1+j]){
                        continue;
                    }
                    else{
                        return;
                    }
                }

                for(int j = 0; j < M; j++){
                    check[i+1+j] = true;
                }

                i = i + M - 1;
            }
        }
    }

    for(int i = N-1; i > 0; i--){
        if(map[row][i] - map[row][i-1] == 1){
            if(i - M < 0){
                return;
            }

            if(M == 1){
                if(check[i-1] == true){
                    return;
                }
                else{
                    check[i-1] = true;
                }
                
            }
            else{
                if(check[i-1] == true){
                    return;
                }
                else{
                    for(int j = 1; j < M; j++){
                        if(check[i-1-j] == false && map[row][i-1] == map[row][i-1-j]){
                            continue;
                        }
                        else{
                            return;
                        }
                    }

                    for(int j = 0; j < M; j++){
                        check[i-1-j] = true;
                    }

                    i = i - M + 1;
                }
            }
        }
    }

    // If there is not trouble, cnt++


    
    cnt++;
    //std::cout << row << " : " << cnt << "\n";
}

void colTravel(int col)
{
    bool check[N];
    for(int i = 0 ; i < N; i++){
        check[i] = false;
    }

    for(int i = 0 ; i < N-1 ; i++){
        if(abs(map[i][col] - map[i+1][col]) > 1){
            return;
        }
        else if((map[i][col] - map[i+1][col]) == 1){
            // Check Slide
            if(i + M > N-1){
                return;
            }

            if(M == 1){
                check[i+1] = true;
            }
            else{
                for(int j = 1; j < M; j++){
                    if(map[i+1][col] == map[i+1+j][col]){
                        continue;
                    }
                    else{
                        return;
                    }
                }

                for(int j = 0; j < M; j++){
                    check[i+1+j] = true;
                }

                i = i + M - 1;
            }
        }
    }

    for(int i = N-1; i > 0; i--){
        if(map[i][col] - map[i-1][col] == 1){
            if(i - M < 0){
                return;
            }

            if(M == 1){
                if(check[i-1] == true){
                    return;
                }
                else{
                    check[i-1] = true;
                }
                
            }
            else{
                if(check[i-1] == true){
                    return;
                }
                else{
                    for(int j = 1; j < M; j++){
                        if(check[i-1-j] == false && map[i-1][col] == map[i-1-j][col]){
                            continue;
                        }
                        else{
                            return;
                        }
                    }

                    for(int j = 0; j < M; j++){
                        check[i-1-j] = true;
                    }

                    i = i - M + 1;
                }
            }
        }
    }


    // If there is not trouble, cnt++
    
    cnt++;

    //std::cout << col << " : " << cnt << "\n";
}

void rowRoad(bool check[], int row)
{
    
}

int main()
{
    
    int result = 0;

    std::cin >> N >> M;

    for(int i = 0 ; i < N; i++){
        for(int j = 0 ;j < N ; j++){
            std::cin >> map[i][j];
        }
    }

    // Row
    for(int i = 0; i < N; i++){
        rowTravel(i);
    }

    // Col
    for(int i = 0; i < N; i++){
        colTravel(i);
    }

    result = cnt;
    std::cout << result << "\n";

    return 0;
}