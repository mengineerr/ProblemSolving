#include <iostream>
#include <string>
#include <vector>


using namespace std;
struct dat{
    int x, y;
};
vector <dat> numPad = {{3,1},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};

int lhand[2] = {3,0};
int rland[2] = {3,2};
int ldist, rdist;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    for(int i = 0; i < numbers.size(); i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += "L";
            lhand[0] = numPad[numbers[i]].x; lhand[1] = numPad[numbers[i]].y;
        }else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer += "R";
            rland[0] = numPad[numbers[i]].x; rland[1] = numPad[numbers[i]].y;
        }else{
            ldist = abs(lhand[0] - numPad[numbers[i]].x) + abs(lhand[1] - numPad[numbers[i]].y);
            rdist = abs(rland[0] - numPad[numbers[i]].x) + abs(rland[1] - numPad[numbers[i]].y);
            if(ldist > rdist){
                answer += "R"; rland[0] = numPad[numbers[i]].x; rland[1] = numPad[numbers[i]].y;
            }else if(ldist < rdist){
                answer += "L"; lhand[0] = numPad[numbers[i]].x; lhand[1] = numPad[numbers[i]].y;
            }else{
                if(hand == "right"){
                answer += "R"; rland[0] = numPad[numbers[i]].x; rland[1] = numPad[numbers[i]].y;
                }else{
                answer += "L"; lhand[0] = numPad[numbers[i]].x; lhand[1] = numPad[numbers[i]].y;
                }
            }
        }
    }
    return answer;
}

