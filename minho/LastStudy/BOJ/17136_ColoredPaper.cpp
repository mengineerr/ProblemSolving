#include <iostream>
#include <algorithm>

int map[10][10] = {0,};
int paper[6] = {0,5,5,5,5,5}; // Num of paper
int result = 987654321;


void sol(int x, int y,int cnt)
{
    if(y == 10){
        sol(x+1,0,cnt);
        return;
    }

    // Finish
    if(x == 10){
        if(result > cnt){
            result = cnt;
        }
        return;
    }

    if(map[x][y] == 0){
        sol(x,y+1,cnt);
        return;
    }

    for(int k = 5; k >= 1; k--){
        // Lack of paper
        if(paper[k] == 0){
            continue;
        }

        // Out of border
        if(x + k - 1 > 9 || y + k - 1 > 9){
            continue;
        }

        bool occupy = true;

        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                if(map[x+i][y+j] == 0){
                    occupy = false;
                    break;
                }
            }

            if(occupy == false){
                break;
            }
        }

        // Don't need to check
        if(occupy == false){
            continue;
        }

        // If paper is occupied
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                map[x+i][y+j] = 0;
            }
        }

        paper[k]--;

        // Check next
        sol(x, y+k,cnt+1);

        // For another case, restore last case.
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                map[x+i][y+j] = 1;
            }
        }

        paper[k]++;
    }
}

int main()
{
    int cnt = 0;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            std::cin >> map[i][j];
        }
    }

    sol(0,0,0);

    if(result == 987654321){
        std::cout << "-1\n";
        return 0;
    }

    std::cout << result << "\n";

    return 0;
}