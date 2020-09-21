#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {

	unordered_map<string, int> MAP;
	for(int i = 0 ; i < clothes.size() ; i++){
		MAP[clothes[i][1]]++;
	}

	int answer = 1;

	for(auto pair : MAP){
		int num = pair.second + 1;
		answer = answer * num;
	}

	return answer - 1;
}

int main(){

	vector<vector<string>> cloth;
	vector<string> temp;

	temp.push_back("yellow_hat");
	temp.push_back("headgear");
	cloth.push_back(temp);
	temp.clear();

	temp.push_back("blue_sunglasses");
	temp.push_back("eyewear");
	cloth.push_back(temp);
	temp.clear();

	temp.push_back("green_turban");
	temp.push_back("headgear");
	cloth.push_back(temp);
	temp.clear();

	cout << solution(cloth);

	return 0;
}
