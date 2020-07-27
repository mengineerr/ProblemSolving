#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

struct location{
    int x;
    int y;
};

using namespace std;

int main()
{
    int N,M = 0;
    int **map;
    cin >> N >> M;

    int min = 987654321;

    vector<location> store;
    vector<location> home;

    map = new int*[N];
    for(int i = 0;i<N;i++)
        map[i] = new int[N];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                struct location temp;
                temp.x = j;
                temp.y = i;
                home.push_back(temp);
            }
            else if(map[i][j] == 2){
                struct location temp;
                temp.x = j;
                temp.y = i;
                store.push_back(temp);
            }
        }
            
    vector<int> perm;
    for(int i =0; i < store.size();i++){
        if(i < M)
            perm.push_back(0);
        else
            perm.push_back(1);
    }

    do{
        int total = 0;
        for(int i = 0; i < home.size();i++){
            int temp = 987654321;
            for(int j =0; j < store.size();j++){
                if(perm[j] == 0){
                    int tmp = abs(store[j].x - home[i].x) + abs(store[j].y - home[i].y);
                    if(tmp < temp)
                        temp = tmp;
                }
            }
            total += temp;
        }

        if(total < min)
            min = total;
    }while(next_permutation(perm.begin(),perm.end()));
    
    cout << min << "\n";
    
    return 0;
}
