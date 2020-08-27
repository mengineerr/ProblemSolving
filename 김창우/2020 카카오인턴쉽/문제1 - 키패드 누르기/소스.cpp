#include <string>
#include <vector>
#include <iostream>

using namespace std;

int minDistance(int start, int arrive){
	int startNum = start;
	int arriveNum = arrive;
	int dis = 0;
	if(startNum == 0) startNum = 11;
	if(arriveNum == 0) arriveNum = 11;

	if(startNum < arriveNum - 1){
		while(startNum < arriveNum - 1){
			startNum = startNum + 3;
			dis++;
		}
	}
	if(startNum > arriveNum + 1){
		while(startNum > arriveNum + 1){
			startNum = startNum - 3;
			dis++;
		}
	}
	dis = dis + abs(startNum - arriveNum);
	return dis;
}

string solution(vector<int> numbers, string hand) {
	string answer;
	int leftHand = 10;
	int rightHand = 12;

    for(int i = 0 ; i < numbers.size() ; i++){
    	if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
    		answer = answer + 'L';
    		leftHand = numbers[i];
    	}else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
    		answer = answer + 'R';
    		rightHand = numbers[i];
    	}else{
    		if(minDistance(leftHand, numbers[i]) == minDistance(rightHand, numbers[i])){
    			if(hand == "right"){
    				answer = answer + 'R';
    				rightHand = numbers[i];
    			}else{
    				answer = answer + 'L';
    				leftHand = numbers[i];
    			}
    		}else if(minDistance(leftHand, numbers[i]) < minDistance(rightHand, numbers[i])){
    			answer = answer + 'L';
    			leftHand = numbers[i];
    		}else{
    			answer = answer + 'R';
    			rightHand = numbers[i];
    		}
    	}
    }

    return answer;
}

int main(){

	vector<int> insertNumbers;
	string inserts;

	while(1){
		cin >> inserts;
		if(inserts != "right" && inserts != "left"){
			int temp = stoi(inserts);
			insertNumbers.push_back(temp);
		}else break;
	}

	cout << solution(insertNumbers, inserts);

	return 0;
}
