#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> num;
vector<char> oper;

int cal(int n1, int n2, char op)
{
    if(op == '+') return n1 + n2;
    else if(op == '-') return n1 - n2;
    else return n1 * n2;
}

int sol()
{
    int ans = -987654321;
    int nidx = 0;
    int oidx = 0;
    int temp = 0;

    if(num.size() == 1){
        return num[0];
    }

    vector<int> n(num.size());
    for(int i = 0; i < num.size();i++){
        n[i] = i;
    }

    vector<int> o(oper.size());
    for(int i = 0; i < oper.size();i++){
        o[i] = i;
    }

    do{
        do{
            nidx = 1;
            oidx = 0;
            temp = num[n[0]];

            while(1){
                if(nidx > num.size()-1){
                    break;
                }

                temp = cal(temp,num[n[nidx]],oper[o[oidx]]);

                nidx++;
                oidx++;
            }

            if(ans < temp){
                ans = temp;
            }
        }
        while(next_permutation(o.begin(),o.end()));
    }
    while(next_permutation(n.begin(),n.end()));


    return ans;
}

int main()
{
    int N = 0;
    string temp;
    int result = 0;

    cin >> N;  
    cin >> temp;

    // Insert num and operator separately
    for(int i = 0; i < temp.length();i++){
        if(temp[i] >= '0' && temp[i] <= '9'){
            num.push_back(temp[i]-'0');
        }
        else{
            oper.push_back(temp[i]);
        }
    }

    result = sol();
    
    cout << result << "\n";

    return 0;
}