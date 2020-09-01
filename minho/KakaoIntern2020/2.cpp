#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<long long> nums; // 입력받은 숫자 저장
vector<char> ops;       // 입력받은 operator 저장
vector<char> op_kind;   // 사용한 operator 종류 저장

long long solution(string expression) {
    long long answer = 0;
    string temp = "";
    for(int i = 0; i < expression.length(); i++){
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
            nums.push_back(stoi(temp));     // stoi 함수
            ops.push_back(expression[i]);
            temp = "";
            if(find(op_kind.begin(),op_kind.end(),expression[i]) == op_kind.end())  // find 함수
                op_kind.push_back(expression[i]);
        }
        else{
            temp += expression[i];
        }
        if(i == expression.length() - 1)
            nums.push_back(stoi(temp));
    }
    
    sort(op_kind.begin(),op_kind.end());    // char도 정렬 가능
    
    do{
        vector<long long> num_tmp = nums;
        vector<char> op_tmp = ops;
        
        for(int i = 0; i < op_kind.size(); i++){
            for(int j = 0; j < op_tmp.size(); j++){
                if(op_kind[i] == op_tmp[j]){
                    switch(op_tmp[j]){
                        case '+':
                                num_tmp[j] += num_tmp[j+1];
                                break;
                        case '-':
                                num_tmp[j] -= num_tmp[j+1];
                                break;
                        case '*':
                                num_tmp[j] *= num_tmp[j+1];
                                break;
                    }
                    num_tmp.erase(num_tmp.begin()+j+1);
                    op_tmp.erase(op_tmp.begin()+j);
                    j--;
                }
            }
        }
        
        if(answer < std::abs(num_tmp[0]))
            answer = std::abs(num_tmp[0]);
    }while(next_permutation(op_kind.begin(),op_kind.end()));
    
    return answer;
}