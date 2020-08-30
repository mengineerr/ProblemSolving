#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

char firstExpress[6] = {'*', '*', '+', '+', '-', '-'};
char secondExpress[6] = {'+', '-', '*', '-', '+', '*'};
char thirdExpress[6] = {'-', '+', '-', '*', '*', '+'};

void printValue(vector<long long> num, vector<char> exp){
	for(int i = 0 ; i < num.size() ; i++){
		cout << num[i] << " ";
	}
	cout << "\n";
	for(int i = 0 ; i < exp.size() ; i++){
		cout << exp[i] << " ";
	}
	cout << "\n";
	cout << "\n";
}

long long calculator(long long number1, long long number2, char expression){
	switch(expression){
		case '*': return number1 * number2;
		break;
		case '+': return number1 + number2;
		break;
		case '-': return number1 - number2;
		break;
	}
}

long long solution(string expression){

    long long answer = 0;
    vector<long long> numbers;
    vector<char> expressions;
    string tempStr;

    for(int i = 0 ; i < expression.length() ; i++){
    	if(expression[i] == '*' || expression[i] == '+' || expression[i] == '-'){
    		expressions.push_back(expression[i]);
    		numbers.push_back(stoull(tempStr));
    		tempStr.clear();
    	}else tempStr = tempStr + expression[i];
    }
    numbers.push_back(stoull(tempStr));
    tempStr.clear();

    for(int i = 0 ; i < 6 ; i++){
    	long long temp = 0;
    	vector<long long> firstNumbers;
   		vector<char> firstExpressions;
    	int calFlag = false;
    	for(int j = 0 ; j < expressions.size() ; j++){
    		if(!calFlag){
    			if(expressions[j] == firstExpress[i]){
    				firstNumbers.push_back(calculator(numbers[j], numbers[j+1], expressions[j]));
    				calFlag = true;
    			}else{
    				firstNumbers.push_back(numbers[j]);
    				firstExpressions.push_back(expressions[j]);
    			}
    		}else{
    			if(expressions[j] == firstExpress[i]){
    				long long realTemp = firstNumbers.back();
    				firstNumbers.pop_back();
    				firstNumbers.push_back(calculator(realTemp, numbers[j+1], expressions[j]));
    				calFlag = true;
    			}else{
    				firstExpressions.push_back(expressions[j]);
    				calFlag = false;
    			}
    		}
    		if(j == expressions.size() - 1 && !calFlag){
    			firstNumbers.push_back(numbers[j+1]);
    		}
    	}
    	//printValue(firstNumbers, firstExpressions);

    	vector<long long> secondNumbers;
   		vector<char> secondExpressions;
    	calFlag = false;
    	for(int j = 0 ; j < firstExpressions.size() ; j++){
    		if(!calFlag){
    			if(firstExpressions[j] == secondExpress[i]){
    				secondNumbers.push_back(calculator(firstNumbers[j], firstNumbers[j+1], firstExpressions[j]));
    				calFlag = true;
    			}else{
    				secondNumbers.push_back(firstNumbers[j]);
    				secondExpressions.push_back(firstExpressions[j]);
    			}
    		}else{
    			if(firstExpressions[j] == secondExpress[i]){
    				long long realTemp = secondNumbers.back();
    				secondNumbers.pop_back();
    				secondNumbers.push_back(calculator(realTemp, firstNumbers[j+1], firstExpressions[j]));
    				calFlag = true;
    			}else{
    				secondExpressions.push_back(firstExpressions[j]);
    				calFlag = false;
    			}
    		}
    		if(j == firstExpressions.size() - 1 && !calFlag){
    			secondNumbers.push_back(firstNumbers[j+1]);
    		}
    	}
    	//printValue(secondNumbers, secondExpressions);

    	for(int j = 0 ; j < secondExpressions.size() ; j++){
    		if(j == 0){
    			temp = calculator(secondNumbers[j], secondNumbers[j+1], secondExpressions[j]);
    		}else{
    			temp = calculator(temp, secondNumbers[j+1], secondExpressions[j]);
    		}
    	}
    	answer = max(answer, abs(temp));
    	//cout << answer << "\n";
    }
    return answer;
}

int main(){
	string inserts;
	cin >> inserts;
	cout << solution(inserts);
	return 0;
}
