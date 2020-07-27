#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>

using namespace std;

int N = 0;

bool search(char region[],vector<vector<int>> link){
    int check[N] = {0,};

    int idx = 0;

    for(int i = 0; i < N; i++){
        if(region[i] == 'A'){
            idx = i;
            break;
        }
    }

    queue<int> q;
    q.push(idx);
    check[idx] = 1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 0; i < link[cur].size(); i++){
            if(region[link[cur][i]] == 'A' && check[link[cur][i]] == 0){
                check[link[cur][i]]=1;
                q.push(link[cur][i]);
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(region[i] == 'B'){
            idx = i;
            break;
        }
    }

    q.push(idx);
    check[idx] = 1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 0; i < link[cur].size(); i++){
            if(region[link[cur][i]] == 'B' && check[link[cur][i]] == 0){
                check[link[cur][i]]=1;
                q.push(link[cur][i]);
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(check[i] == 1)
            cnt++;
    }
    
    if(cnt == N)
        return true;
    else
        return false;
}

int main()
{
    cin >> N;

    int population[N] = {0,};
    for(int i = 0; i < N; i++)
        cin >> population[i];

    vector<vector<int>> link(N);

    int num,temp = 0;

    for(int i = 0; i < N; i++){
        cin >> num;
        for(int j = 0; j < num; j++){
            cin >> temp;
            link[i].push_back(temp-1);
        }
    }

    int min = 987654321;

    for(int i = 1; i < N; i++){
        vector<int> perm;
        for(int j = 0; j < N; j++){
            if(j < i)
                perm.push_back(1);
            else
                perm.push_back(0);
        }
        
        do{
            char region[N];

            int totalA = 0,totalB = 0;
            
            for(int i = 0; i < N; i++){
                if(perm[i] == 1){
                    region[i] = 'A';
                    totalA += population[i];
                }
                else{
                    region[i] = 'B';
                    totalB += population[i];
                }
            }

            // 선거구가 2개 넘으면 스킵
            bool flag = search(region,link);

            if(flag == false)
                continue;

            // 인구 계산
            if(min > abs(totalA - totalB)){
                min = abs(totalA - totalB);
            }
        }while(prev_permutation(perm.begin(),perm.end()));
    }

    if(min == 987654321){
        cout << "-1\n";
        return 0;
    }

    cout << min << "\n";

    return 0;
}