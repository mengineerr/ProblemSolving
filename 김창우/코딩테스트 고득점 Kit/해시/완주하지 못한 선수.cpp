#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    unordered_map<string, int> m;

    for(string name : participant) m[name]++;
    for(string name : completion) m[name]--;
    for(auto pair : m){
    	if(pair.second > 0){
    		return pair.first;
    	}
    }
}

int main(){

	vector<string> participants;
	vector<string> completions;

	participants.push_back("leo");
	participants.push_back("kiki");
	participants.push_back("eden");

	completions.push_back("eden");
	completions.push_back("kiki");

	cout << solution(participants, completions);

	return 0;
}
