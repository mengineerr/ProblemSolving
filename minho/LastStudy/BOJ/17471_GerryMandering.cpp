#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

int N = 0;
int result = 99999999;
bool visit[10] = {false,};
vector < vector <int> > link;

void permutation(vector<int> &section, int num){
    for(int i = 0; i < N; i++){
        if(i < num){
            section[i] = 1;
        }
        else{
            section[i] = 0;
        }
    }
}

void travel(vector<int> &section, int idx){
    queue <int> q;
    q.push(idx);
    visit[idx] = true;
    int nidx = 0;

    while(!q.empty()){
        nidx = q.front();
        q.pop();

        for(int i = 0; i < link[nidx].size(); i++){
            if(visit[link[nidx][i]] == false && ( section[idx] == section[link[nidx][i]] )){
                q.push(link[nidx][i]);
                visit[link[nidx][i]] = true;
            }
        }
    }
}


int main()
{
    std::cin >> N;

    // Write population
    int population[N] = {0,};
    for(int i = 0; i < N;i++){
        cin >> population[i];
    }

    int check0 = 0;

    for(int i = 0; i < N; i++){
        link.push_back(vector<int>());
    }

    for(int i = 0; i < N; i++){
        int temp = 0;
        cin >> temp;

        if(temp == 0){
            check0++;
        }

        int element = 0;

        for(int j = 0; j < temp; j++){
            cin >> element;
            link[i].push_back(element-1);
        }
    }

    /*
    for(int i = 0 ; i < N ; i++){
        vector <int> element;
        element.clear();

        int temp = 0;
        cin >> temp;

        if(temp == 0){
            check0++;
        }

        for(int j = 0; j < temp; j++){
            int temp2 = 0;
            cin >> temp2;
            element.push_back(temp2-1);
        }

        link.push_back(element);
    }
    */

    // ----------Sol Start----------

    // If number of linkless region is more than 2, print -1.
    if(check0 > 2){
        cout << "-1\n";
        return 0;
    }

    // Using Permutation

    vector<int> section;
    
    for(int i = 0; i < N; i++){
        section.push_back(0);
    }

    for(int i = 0; i <= N/2 ; i++){
        permutation(section,i);

        do{
            
            for(int j = 0; j < N; j++){
                visit[j] = false;
            }
            

            //memset(visit,false,sizeof(visit));

            int val1 = 0, val2 = 0;
            int idx1 = 0, idx2 = 0;
            bool select1 = false, select2 = false;

            for(int j = 0; j < N; j++){
                if(section[j] == 0 && select1 == false){
                    idx1 = j;
                    select1 = true;
                }

                if(section[j] == 1 && select2 == false){
                    idx2 = j;
                    select2 = true;
                }

                if(select1 == true && select2 == true){
                    break;
                }
            }

            travel(section, idx1);
            travel(section, idx2);
            
            int cnt = 0;

            for(int j = 0; j < N; j++){
                if(visit[j] == true){
                    cnt++;
                }
            }

            if(cnt == N){
                for(int j = 0; j < N; j++){
                    if(section[j]){
                        val1 += population[j];
                    }
                    else{
                        val2 += population[j];
                    }
                }

                if(result > abs(val1 - val2)) result = abs(val1 - val2);
            }
        }
        while(prev_permutation(section.begin(),section.end()));
    }

    if(result == 99999999){
        cout << "-1\n";
    }
    else{
        cout << result << "\n";
    }

    return 0;
}