#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector <int> opPrior = {0, 1, 2};  // 0 - + 1 - - 2 - *
int opNum[3] = {0, 0, 0};
vector <long long> numSet;
vector <int> opSet;
vector <long long> copyNum(){
    vector <long long> v;
    for(long long a : numSet) v.push_back(a);
    return v;
}
vector <int> copyOp(){
    vector <int> v;
    for(int a : opSet) v.push_back(a);
    return v;
}
long long calc(long long num1, long long num2, int n){
    switch (n)
    {
    case 0:
        return num1 + num2;
    case 1:
        return num1 - num2;
    case 2:
        return num1 * num2;
    default:
        break;
    }
    return 0;
}
void init(string s){
    string temp = "";
    long long num = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '+' || s[i] == '*' || s[i] == '-'){
            num = stoll(temp);
            numSet.push_back(num);
            temp = "";
            num = 0;
            if(s[i] == '+'){
                opSet.push_back(0); opNum[0]++;
            }
            if(s[i] == '-'){
                opSet.push_back(1); opNum[1]++;
            }
            if(s[i] == '*'){
                opSet.push_back(2); opNum[2]++;
            }                        
        }else{
            temp += s[i];
        }
    }
    num = stoll(temp);
    numSet.push_back(num);
}
long long solution(string expression) {
    long long answer = 0;
    init(expression);
    sort(opPrior.begin(), opPrior.end());
    do{
        vector <long long> cnum = copyNum();
        vector <int> cop = copyOp(); 
        for(int op : opPrior){
            int cnt = opNum[op];
            int idx = 0;
            while (cnt!=0){
                if(op != cop[idx]){
                    idx++;
                }else{
                    long long num = calc(cnum[idx],cnum[idx+1], op);
                    cnum.erase(cnum.begin()+idx); cnum.erase(cnum.begin()+idx);
                    cnum.insert(cnum.begin()+idx, num);
                    cop.erase(cop.begin()+idx);
                    cnt--;
                }
            }
        }
        answer = max(answer, abs(cnum[0]));
    }while(next_permutation(opPrior.begin(), opPrior.end()));
    return answer;
}
