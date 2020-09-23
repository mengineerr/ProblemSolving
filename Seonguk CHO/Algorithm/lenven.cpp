#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

string input1, intput2;
int dist[1001][1001];


int levenshtein(string &s1, string &s2){
    for(int i = 1; i <=s1.length(); i++) dist[i][0] = i;
    for(int j = 1; j <=s2.length(); j++) dist[0][j] = j;

    for(int j = 1; j <= s2.length(); j++){
        for(int i = 1; i <= s1.length(); i++){
            if(s1[i-1] == s2[j-1]) dist[i][j] = dist[i-1][j-1];
            else dist[i][j] = min(dist[i-1][j-1]+1, min(dist[i][j-1]+1, dist[i-1][j]+1));
        }
    }
}
int main(){

}