#include <iostream>
#include <vector>

std::vector<std::vector<int>> link;
bool visit[101] = {false,};
int result = 0;

void corona(int n){
    
    visit[n] = true;

    for(int i = 0; i < link[n].size(); i++){
        if(visit[link[n][i]] == false){
            corona(link[n][i]);
            result++;
        }
    }

    return;
}

int main()
{
    int num = 0;
    std::cin >> num;

    link.resize(num + 1);

    int link_num = 0;
    std::cin >> link_num;

    int from,to = 0;

    for(int i = 0; i < link_num; i++){
        std::cin >> from >> to;

        link[from].push_back(to);
        link[to].push_back(from);
    }


    corona(1);

    std::cout << result << "\n";
}