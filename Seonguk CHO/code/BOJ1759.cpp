#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int l,c;

vector <string> v;
vector <int> set;
vector <string> ans;
bool chk(){
    int cnt1 = 0; int cnt2 = 0;
    for(int i = 0; i < ans.size(); i++){
        if(ans[i] == "a" || ans[i] == "e"  || ans[i] == "i"  || ans[i] == "o"  || ans[i] == "u" ){
            cnt1++;
        }else{
            cnt2++;
        }
    }
    if(cnt1>=1&&cnt2>=2) return true;
    return false;
}
int main(){
    cin >> l >> c;
    for(int i = 0; i < c; i++){
        string t;
        cin >> t; v.push_back(t);
    }
    for(int i = 0; i < l; i++) set.push_back(1);
    for(int i = 0; i < c-l; i++) set.push_back(0);
    sort(v.begin(), v.end());// 문자열 사전순
    do{
        for(int i = 0; i < set.size(); i++){
            if(set[i] == 1){
                ans.push_back(v[i]);
            }
        }
        if(chk()){
            for(int i = 0; i < ans.size(); i++) cout << ans[i];
            cout << endl;
        }
        ans.clear();
       
    }while(prev_permutation(set.begin(), set.end()));
    return 0;

}