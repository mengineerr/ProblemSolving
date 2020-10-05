#include <iostream>
#include <vector>

std::vector <int> con[1001];
bool check[1001];

void Travel(int i){
    check[i] = true;
    int next = 0;

    for(int j = 0; j < con[i].size() ; j++){
        next = con[i][j];

        if(check[next] == false) Travel(next);
    }
}

int main()
{
    std::cin.sync_with_stdio(false);

    int N, M = 0;
    std::cin >> N  >> M;
    int u,v = 0;
    int ans = 0;

    for(int i = 0; i < M; i++){
        std::cin >> u >> v;
        con[u].push_back(v);
        con[v].push_back(u);
    }

    for(int i = 1; i <= N; i++){
        if(check[i] == false){
            Travel(i);
            ans++;
        }
    }

    std::cout << ans << "\n";
}