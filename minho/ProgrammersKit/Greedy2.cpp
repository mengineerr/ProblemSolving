#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int num_len = number.length() - k;
    int start = 0;
    int last = number.length() - num_len;
    
    for(int i = last; i < number.length(); i++){
        char tmp = '0';
        for(int j = start; j <= i; j++){
            if(number[j] > tmp){
                tmp = number[j];
                start = j;
            }
        }
        number[start] = '0';
        answer += tmp;
    }
    
    return answer;
}
 
