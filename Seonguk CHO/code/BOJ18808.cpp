#include <iostream>
#include <cstring>

using namespace std;

#define MAX 41
int n, m, k;
int map[MAX][MAX];
struct sticker{
    int ori[11][11];
    int rot[11][11];
    int hlen, vlen;
    int num = 0;
};
sticker s[101];
int ans = 0;
bool chk(int x, int y, int num){
    sticker &sel = s[num];
    for(int i = 0; i < sel.vlen; i++){
        for(int j = 0; j < sel.hlen; j++){
            if(map[x+i][y+j] == 1 && sel.ori[i][j] == 1) return false;
        }
    }
    return true;
}
void put(int x, int y, int num){
    sticker &sel = s[num];
    for(int i = 0; i < sel.vlen; i++){
        for(int j = 0; j < sel.hlen; j++){
            if(sel.ori[i][j] == 1) map[x+i][y+j] = 1;
        }
    }
}
bool locate(int num){
    for(int i = 0; i <= n - s[num].vlen; i++){
        for(int j = 0; j <= m - s[num].hlen; j++){
            if(chk(i,j,num)){
                put(i,j,num);
                ans += s[num].num;
                return true;
            }
        }
    }
    return false;
}
// r- vlen c -
void printMap(int num){
    sticker &a = s[num];
    cout << endl;
    for(int i = 0; i < a.vlen; i++){
        for(int j = 0; j < a.hlen; j++){
            cout << a.rot[i][j]<< " ";
        }
        cout << endl;
    }
}
void rotate(int num){
    sticker &sel = s[num];
    memset(sel.rot, 0, sizeof(sel.rot));
    for(int i = 0; i < sel.hlen; i++){
        for(int j = 0; j < sel.vlen; j++){
            sel.rot[i][j] = sel.ori[sel.vlen-j-1][i];
        }
    }
    int temp = sel.vlen;
    sel.vlen = sel.hlen; sel.hlen = temp;
    memset(sel.ori, 0, sizeof(sel.ori));
    for(int i = 0; i < sel.vlen; i++){
        for(int j = 0; j < sel.hlen; j++) sel.ori[i][j] = sel.rot[i][j];
    }
}
void solve(){
    bool flag;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < 4; j++){
            if(locate(i)) break;
            rotate(i);
 
        }
    }
}
int main(){
    cin >> n >> m >> k;
    memset(map, 0, sizeof(map));
    // 스티커를 차례대로 붙인다. 

    for(int i = 0; i < k; i++){
        cin >> s[i].vlen >> s[i].hlen;
        for(int j = 0; j < s[i].vlen; j++){
            for(int k = 0; k < s[i].hlen; k++){
                cin >> s[i].ori[j][k];
                if(s[i].ori[j][k] == 1) s[i].num++;
            }
        }
    }
    solve();
    cout << ans;
    return 0;
}