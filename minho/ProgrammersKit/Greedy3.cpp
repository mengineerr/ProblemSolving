#include <string>
#include <vector>
#include <iostream>

using namespace std;

int names[20] = {0};

int solution(string name) {
    int answer = 0;
    int name_len = name.length();
    
    for(int i = 0; i < name_len; i++){
        names[i] = name[i] - 'A';
        if(names[i] > 26 - names[i])
            names[i] = 26 - names[i];
    }
    
    int cur = 0;
    string comp = "";
    for(int i = 0; i < name_len; i++)
        comp += "A";
    
    while(comp != name){
        int right = 0;
        int left = 0;
        
        for(int i = 0; i < name_len; i++){
            int loc = (cur + i < name_len) ? cur + i : cur + i - name_len;
            if(comp[loc] != name[loc]){
                right = i;
                break;
            }
        }
        
        for(int i = 0; i < name_len; i++){
            int loc = (cur - i >= 0) ? cur - i : cur - i + name_len;
            if(comp[loc] != name[loc]){
                left = i;
                break;
            }
        }
        
        if(right <= left){
            answer += right;
            int loc = (cur + right < name_len) ? cur + right : cur + right - name_len;
            comp[loc] = name[loc];
            answer += names[loc];
            cur = loc;
        }
        else{
            answer += left;
            int loc = (cur - left >= 0) ? cur - left : cur - left + name_len;
            comp[loc] = name[loc];
            answer += names[loc];
            cur = loc;
        }
    }
    
    return answer;
}
