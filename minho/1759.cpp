#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int L, C = 0;
    cin >> L >> C;

    vector<char> set;
    char tmp;

    for(int i = 0; i < C; i++){
        cin >> tmp;
        set.push_back(tmp);
    }

    sort(set.begin(),set.end());

    vector<int> per;

    for(int i = 0; i < C; i++){
        if(i < L)
            per.push_back(0);
        else
            per.push_back(1);
    }

    vector<vector<char>> ans;

    do{
        int vocoid = 0;
        int consonant = 0;
        vector<char> val;
        for(int i = 0; i < C; i++){
            if(per[i] == 0){
                val.push_back(set[i]);
                tmp = set[i];
                if(tmp == 'a' || tmp == 'e' || tmp == 'i' || tmp == 'o' || tmp == 'u')
                    vocoid++;
                else
                    consonant++;
            }
        }

        if(vocoid > 0 && consonant > 1){
            for(int i = 0; i < L; i++){
                cout << val[i];
            }
            cout << "\n";
        }
    }while(next_permutation(per.begin(),per.end()));

    return 0;
}