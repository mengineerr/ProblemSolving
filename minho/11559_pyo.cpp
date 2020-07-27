#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char **map;
int **check;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

struct location{
    int x;
    int y;
};

vector<location> v;

void range(){
    vector<vector<char>> v(6);

    for(int j = 0; j < 6; j++){
        for(int i = 11; i >= 0; i--){
            if(map[i][j] != '.')
                v[j].push_back(map[i][j]);
        }
    }

    for(int j = 0; j < 6; j++){
        for(int i = 0; i < 12; i++){
            if(i < v[j].size())
                map[11-i][j] = v[j][i];
            else
                map[11-i][j] = '.';
        }
    }
}

void bfs(int y, int x){
    char color = map[y][x];
    check[y][x] = 1;

    for(int i = 0; i < 4; i++){
        if(x + dx[i] < 0 || x + dx[i] > 5 || y + dy[i] < 0 || y + dy[i] > 11)
            continue;
        if(check[y+dy[i]][x+dx[i]] == 1)
            continue;
        if(map[y+dy[i]][x+dx[i]] == color){
            struct location temp;
            temp.x = x + dx[i];
            temp.y = y + dy[i];
            v.push_back(temp);
            bfs(y+dy[i],x+dx[i]);
        }
    }
}

int sol(){
    int ans = 0;
    for(int i = 0; i < 12; i++)
        for(int j = 0; j < 6; j++)
            check[i][j] = 0;

    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            if(map[i][j] == '.')
                check[i][j] = 1;
            else if(check[i][j] == 1)
                continue;
            else{
                v.clear();
                struct location cur;
                cur.x = j;
                cur.y = i;
                v.push_back(cur);
                
                bfs(i,j);

                if(v.size() >= 4){
                    for(int k = 0; k < v.size(); k++)
                        map[v[k].y][v[k].x] = '.';
                    ans = 1;
                }
            }
        }
    }

    return ans;
}

int main()
{
    map = new char*[12];
    for(int i = 0; i < 12; i++)
        map[i] = new char[6];

    check = new int*[12];
    for(int i = 0; i < 12; i++)
        check[i] = new int[6];


    for(int i = 0; i < 12; i++)
        for(int j = 0; j < 6; j++)
            cin >> map[i][j];       
    
    int chain = 0;

    while(1){
        int temp = sol();

        if(temp == 0)
            break;
        
        chain += temp;

        range();
    }

    cout << chain << "\n";

    return 0;
}