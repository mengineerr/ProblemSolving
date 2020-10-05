#include <iostream>
#include <algorithm>
#include <cstdlib>

int N = 0;
int **A;    // Assign Pointer for ease
int **region;
int Human[5] = {0,};
int total = 0;

void Divide(const int i, const int j, const int d1, const int d2)
{
    int x = 0, y = 0;
    int distance = 0;

    for(int k = 0; k < N; k++){
        for(int l = 0; l < N; l++){
            region[k][l] = 5;
        }
    }

    //region 1
    x = i + d1;
    y = j;
    
    for(int r = 0; r < x; r++){
        for(int c = 0; c <= y; c++){
            distance = abs(r-x) + abs(c - y);
            if(distance > d1){
                region[r][c] = 1;
            }
        }
    }

    //region 2
    x = i + d2;
    y = j;

    for(int r = 0; r <= x; r++){
        for(int c = y+1; c < N; c++){
            distance = abs(r-x) + abs(c - y);
            if(distance > d2){
                region[r][c] = 2;
            }
        }
    }

    //region 3
    x = i + d1;
    y = j - d1 + d2;

    for(int r = x; r < N; r++){
        for(int c = 0; c < y; c++){
            distance = abs(r-x) + abs(c - y);
            if(distance > d2){
                region[r][c] = 3;
            }
        }
    }

    //region 4
    x = i + d2;
    y = j + d2 - d1;

    for(int r = x+1; r < N; r++){
        for(int c = y; c < N; c++){
            distance = abs(r-x) + abs(c - y);
            if(distance > d1){
                region[r][c] = 4;
            }
        }
    }

    
}

int sum(const int i, const int j, const int d1, const int d2)
{
    int ans = 0;

    for(int i = 0; i < 5; i++){
        Human[i] = 0;
    }

    Divide(i,j,d1,d2);

    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            if(region[r][c] == 1){
                Human[0] += A[r][c];
            }
            if(region[r][c] == 2){
                Human[1] += A[r][c];
            }
            if(region[r][c] == 3){
                Human[2] += A[r][c];
            }
            if(region[r][c] == 4){
                Human[3] += A[r][c];
            }
            if(region[r][c] == 5){
                Human[4] += A[r][c];
            }
        }
    }

    std::sort(Human,Human+5);

    ans = Human[4] - Human[0];

    return ans;
}


int scan(const int i, const int j)
{
    int temp = 0;
    int ans = 9999999;
    int d1 = 1, d2 = 1;

    // Need to add d1, d2 variation!!!
    for(int d1 = 1; d1 < N; d1++){
        for(int d2 = 1; d2 < N; d2++){
            if(i + d1 + d2 > N - 1){
                break;
            }

            if(j - d1 < 0){
                break;
            }

            if(j + d2 > N-1){
                break;
            }

            temp = sum(i,j,d1,d2);
            if(ans > temp){
                ans = temp;
            }
        }
    }
    
    return ans;
}

int sol()
{
    int ans = 99999999;
    int val = 0;

    // Do not check Border. d1, d2 > 0
    for(int i = 1; i < N-1; i++){
        for(int j = 1; j < N-1; j++){
            val = scan(i,j);

            if(ans > val){
                ans = val;
            }
        }
    }

    return ans;
}

int main()
{
    std::cin >> N;

    
    A = new int*[N];
    for(int i = 0; i < N; i++){
        A[i] = new int[N];
    }

    region = new int*[N];
    for(int i = 0; i < N; i++){
        region[i] = new int[N];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cin >> A[i][j];
            total += A[i][j];
        }
    }

    int result = 0;
    result = sol();

    std::cout << result << "\n";

    // deallocate array
    for(int i = 0; i < N; i++){
        delete [] A[i];
    }

    delete[] A;

    return 0;
}