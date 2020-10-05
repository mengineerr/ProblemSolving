#include <iostream>
#include <queue>

int walk[2] = {-1,1};
bool visit[100001] = {false,};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); 
    std::cout.tie(NULL);

    int N =0 , K = 0;
    std::cin >> N >> K;

    std::queue<std::pair<int,int>> q;

    int loc = 0;
    int time = 0;

    q.push(std::make_pair(N,0));

    while(!q.empty())
    {
        loc = q.front().first;
        time = q.front().second;
        q.pop();

        if(loc == K){
            std::cout << time << "\n";
            return 0;
        }

        for(int i = 0; i < 2; i++){
            if(loc + walk[i] >= 0 && loc + walk[i] <= 100000){
                if(visit[loc + walk[i]] == false){
                    q.push(std::make_pair(loc + walk[i], time + 1));
                    visit[loc + walk[i]] = true;
                }
            }
        }

        if(loc * 2 <= 100000){
            if(visit[loc * 2] == false){
                q.push(std::make_pair(loc * 2, time + 1));
                visit[loc * 2] = true;
            }
        }
    }
    
    return 0;
}