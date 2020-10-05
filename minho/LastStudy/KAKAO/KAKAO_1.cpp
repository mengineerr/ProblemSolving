#include <iostream>
#include <vector>
#include <string>

using namespace std;

int scan(const string s, const int len)
{
    string ans;
    string cmp;
    int idx = 0;
    int cnt = 0;
    bool flag = true;
    
    while(idx < s.length()){
        // Copy Test String
        if(cmp.empty()){
            for(int i = 0; i < len; i++){
                if(idx+i >= s.length()){
                    break;
                }
                cmp.push_back(s[idx+i]);
            }

            cnt = 0;
        }

        flag = true;    // Test Duplicated Case

        for(int i = 0; i < cmp.length(); i++){
            if(cmp[i] != s[idx+i]){
                flag = false;
            }
            if(flag == false){
                break;
            }
        }

        if(flag == false){  // Non-Duplicated Anymore
            if(cnt > 1) ans += to_string(cnt);
            ans += cmp;
            cmp.clear();
        }
        else{   // Duplicated Case
            cnt++;
            idx += len;

            if(idx >= s.length()){
                if(cnt > 1) ans += to_string(cnt);
                ans += cmp;
                cmp.clear();
            }
        }
    }

    // Before Submition, delete it
    //cout << len << " : " << ans << " , " << ans.length() << "\n";

    return ans.length();
}

int solution(string s) {
    int answer = 0;
    int temp = 0;

    cin >> s;

    answer = s.length();

    for(int i = 1; i < s.length(); i++){
        if(i > s.length()/2){
            break;
        }

        temp = scan(s,i);
        if(answer > temp){
            answer = temp;
        }
    }

    // Before Submition, delete it
    cout << answer << "\n";

    return answer;
}

int main()
{
    string s;
    solution(s);

    return 0;
}