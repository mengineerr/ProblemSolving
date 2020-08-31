#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct loc{
    int y; int x;
};

loc right_cur = {3,2};
loc left_cur = {3,0};

string checkHand(int num, string hand){
    if(num == 1 || num == 4 || num == 7){
        if(num == 1)
            left_cur = {0,0};
        else if(num == 4)
            left_cur = {1,0};
        else
            left_cur = {2,0};
        return "L";
    }
    else if(num == 3 || num == 6 || num == 9){
        if(num == 3)
            right_cur = {0,2};
        else if(num == 6)
            right_cur = {1,2};
        else
            right_cur = {2,2};
        return "R";
    }
    else if(num == 2 || num == 5 || num == 8 || num == 0){
        int loc = 0;
        if(num == 2) loc = 0;
        else if(num == 5) loc = 1;
        else if(num == 8) loc = 2;
        else loc = 3;
        
        int right_len = std::abs(right_cur.y - loc) + std::abs(right_cur.x - 1);
        int left_len = std::abs(left_cur.y - loc) + std::abs(left_cur.x - 1);
        
        if(right_len < left_len){
            right_cur = {loc,1};
            return "R";
        }
        else if(right_len > left_len){
            left_cur = {loc,1};
            return "L";
        }
        else{
            if(hand == "right"){
                right_cur = {loc,1};
                return "R";
            }
            else{
                left_cur = {loc,1};
                return "L";
            }
        }
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    for(int next : numbers)
        answer += checkHand(next,hand);
    
    return answer;
}