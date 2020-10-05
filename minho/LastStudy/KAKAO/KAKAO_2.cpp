#include <string>
#include <queue>
#include <iostream>

using namespace std;

string solution(string p) {
    string answer = "";

    // Check Empty Case
    if(p.empty()){
        return answer;
    }

    string u;
    string v;
    u.clear(), v.clear();
    

    int check = 0;
    bool right = true;

    for(int i = 0; i < p.length(); i++){
        if(p[i] == '('){
            check++;
        }
        else if(p[i] == ')'){
            check--;
        }

        if(check < 0 && right == true){
            right = false;
        }

        if(check == 0 && right == false){
            right = true;
            v.push_back(p[i]);
            continue;
        }

        if(right == true){
            u.push_back(p[i]);
        }
        else if(right == false){
            v.push_back(p[i]);
        }
    }

    v.erase(0);
    v.erase(v.length()-1);

    for(int i = 0; i < v.length(); i++){
        if(v[i] == '('){
            v[i] = ')';
        } 
        else if(v[i] == ')'){
            v[i] = '(';
        } 
    }

    v = "(" + v + ")";

    answer = u + v;

    cout << answer << "\n";

    return answer;
}

int main()
{
    string p;
    cin >> p;
    solution(p);

    return 0;
}