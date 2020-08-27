#include <iostream>
#include <vector>
#define MAX 40

using namespace std;

int map[MAX][MAX] = {0};
int N = 0, M = 0, K = 0;
int total = 0;

void attachSticker(){
    int row,col;
    cin >> row >> col;
    int sticker[row][col] = {0};
    int sticker90[col][row] = {0}; 
    int sticker180[row][col] = {0};
    int sticker270[col][row] = {0};
    int cnt = 0;

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++){
            cin >> sticker[i][j];    // Input 0 degree
            sticker90[j][row-i-1] = sticker[i][j];    // Input 90 degree
            sticker180[row - 1 - i][col - 1 - j] = sticker[i][j];    // Input 180 degree
            sticker270[col-j-1][i] = sticker[i][j];   // Input 270 degree

            if(sticker[i][j] == 1) cnt++;
        }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            bool test = true;

            for(int p = 0; p < row; p++){
                for(int q = 0; q < col; q++){
                    if(test == false) continue;
                    if(map[i+p][j+q] == 1 && sticker[p][q] == 1)  test = false;
                    if(i+p > N-1 || j + q > M-1) test = false;
                }
            }

            if(test == true){
                for(int p = 0; p < row; p++){
                    for(int q = 0; q < col; q++){
                        if(sticker[p][q] == 1)
                            map[i+p][j+q] = sticker[p][q]; 
                    }
                }
                total += cnt;
                return;
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            bool test = true;

            for(int p = 0; p < col; p++){
                for(int q = 0; q < row; q++){
                    if(test == false) continue;
                    if(map[i+p][j+q] == 1 && sticker90[p][q] == 1)  test = false;
                    if(i+p > N-1 || j + q > M-1) test = false;
                }
            }

            if(test == true){
                for(int p = 0; p < col; p++){
                    for(int q = 0; q < row; q++){
                        if(sticker90[p][q] == 1)
                            map[i+p][j+q] = sticker90[p][q]; 
                    }
                }
                total += cnt;
                return;
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            bool test = true;

            for(int p = 0; p < row; p++){
                for(int q = 0; q < col; q++){
                    if(test == false) continue;
                    if(map[i+p][j+q] == 1 && sticker180[p][q] == 1)  test = false;
                    if(i+p > N-1 || j + q > M-1) test = false;
                }
            }

            if(test == true){
                for(int p = 0; p < row; p++){
                    for(int q = 0; q < col; q++){
                        if(sticker180[p][q] == 1)
                            map[i+p][j+q] = sticker180[p][q]; 
                    }
                }
                total += cnt;
                return;
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            bool test = true;

            for(int p = 0; p < col; p++){
                for(int q = 0; q < row; q++){
                    if(test == false) continue;
                    if(map[i+p][j+q] == 1 && sticker270[p][q] == 1)  test = false;
                    if(i+p > N-1 || j + q > M-1) test = false;
                }
            }

            if(test == true){
                for(int p = 0; p < col; p++){
                    for(int q = 0; q < row; q++){
                        if(sticker270[p][q] == 1)
                            map[i+p][j+q] = sticker270[p][q]; 
                    }
                }
                total += cnt;
                return;
            }
        }
    }
}

int main()
{
    cin >> N >> M >> K;
    
    for(int i = 0; i < K; i++)
        attachSticker();
        
    cout << total << "\n";
    
    return 0;
}