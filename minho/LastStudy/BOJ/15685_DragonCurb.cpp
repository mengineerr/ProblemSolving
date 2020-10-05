#include <iostream>
#include <vector>

int map[101][101] = {0,};

void check(int x, int y , int d , int g){
    std::vector<int> v;
    v.push_back(d);
    int size = 0;
    int dir = 0;

    for(int i = 0; i< g; i++){
        size = v.size();

        for(int j = size-1; j >= 0; j--){
            dir = v[j];
            int NextDir = (dir + 1 ) % 4;
            v.push_back(NextDir);
        }
    }

    size = v.size();
    map[x][y] = 1;

    for(int i = 0; i < size ; i++){
        dir = v[i];

        switch (dir)
        {
            case 0 : ++x; break;
            case 1 : --y; break;
            case 2 : --x; break;
            case 3 : ++y; break;
        }

        map[x][y] = 1;
    }
}

int main()
{
    int N = 0;
    std::cin >> N;
    int x , y , d, g = 0;

    for(int i = 0; i<N; i++){
        std::cin >> x >> y >> d >>g;
        check(x,y,d,g);
    }

    int ans = 0;

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100 ; j++){
            if (map[i][j]){
                if(map[i+1][j] && map[i][j+1] && map[i+1][j+1]) ans++;
            }
        }
    }

    std::cout << ans << "\n";
}