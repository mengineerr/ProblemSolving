#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    int N,M,T;
    int **map;
    int xi,di,ki;
    cin >> N >> M >> T;

    map = new int*[N];
    for(int i = 0; i < N; i++)
        map[i] = new int[M];
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> map[i][j];

    // 각 배열의 위쪽을 바라보는 index를 저장
    int index[N] = {0,};

    for(int i = 0; i < T; i++){
        cin >> xi >> di >> ki;
        int cnt = 1;    //배수

        // 회전
        while(xi * cnt <= N){
            int cur = xi * cnt - 1;
            if(di == 0){
                index[cur] -= ki;
                index[cur] = (index[cur] > 0) ? index[cur] : (index[cur] + M);
            }
            else{
                index[cur] += ki;
                index[cur] = (index[cur] < M) ? index[cur] : (index[cur] - M);
            }
            
            cnt++;
        }

        // 지워야할 위치를 저장할 영역
        int deleteloc[N][M];
        memset(deleteloc,0,sizeof(deleteloc));

        bool flag = false;
        float avg = 0;
        float num = 0;

        // 중복 찾기
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                int curidx = (index[i] + j < M) ? (index[i] + j) : (index[i] + j - M);
                int nextidx = (curidx + 1 < M) ? (curidx + 1) : (curidx + 1 - M);
                // 수가 지워진 경우
                if(map[i][curidx] == -1)
                    continue;
                // 가로
                if(map[i][curidx] == map[i][nextidx]){
                    deleteloc[i][curidx] = -1;
                    deleteloc[i][nextidx] = -1;
                    flag = true;
                }
                // 세로
                if(i < N-1){
                    int upidx = (index[i+1] + j < M) ? (index[i+1] + j) : (index[i+1] + j - M);
                    if(map[i][curidx] == map[i+1][upidx]){
                        deleteloc[i][curidx] = -1;
                        deleteloc[i+1][upidx] = -1;
                        flag = true;
                    }
                }
                avg += (float)map[i][curidx];
                num++;
            }
        }
        avg /= num;

        // 지울 수가 없는 경우
        if(flag == false){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    if(map[i][j] == -1)
                        continue;
                    if(map[i][j] > avg)
                        map[i][j]--;
                    else if(map[i][j] < avg)
                        map[i][j]++;
                }
            }
        }

        // 숫자 지우기
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(deleteloc[i][j] == -1)
                    map[i][j] = -1;
            }
        }
    }

    int total = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] != -1)
                total += map[i][j];
        }
    }
    cout << total << "\n";

    return 0;
}