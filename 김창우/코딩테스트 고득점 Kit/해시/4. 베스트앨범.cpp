#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct DATA{
	int first_num, first_play, second_num, second_play, total, count;
};

vector<int> solution(vector<string> genres, vector<int> plays) {

	vector<int> answer;
	unordered_map<string, DATA> MAP;
	unordered_map<int, string> ANSWERMAP;
	vector<int> ANSWERVECTOR;

	for(int i = 0 ; i < genres.size() ; i++){
		MAP[genres[i]].total = MAP[genres[i]].total + plays[i];
		MAP[genres[i]].count++;
		if(plays[i] > MAP[genres[i]].first_play){
			MAP[genres[i]].second_play = MAP[genres[i]].first_play;
			MAP[genres[i]].second_num = MAP[genres[i]].first_num;
			MAP[genres[i]].first_play = plays[i];
			MAP[genres[i]].first_num = i;
		}else if(plays[i] == MAP[genres[i]].first_play){
			MAP[genres[i]].second_play = plays[i];
			MAP[genres[i]].second_num = i;
		}else if(plays[i] < MAP[genres[i]].first_play){
			if(plays[i] > MAP[genres[i]].second_play){
				MAP[genres[i]].second_play = plays[i];
				MAP[genres[i]].second_num = i;
			}
		}
	}

	for(auto pair : MAP){
		ANSWERVECTOR.push_back(pair.second.total);
		ANSWERMAP[pair.second.total] = pair.first;
	}

	sort(ANSWERVECTOR.begin(), ANSWERVECTOR.end(), greater<int>());

	for(int i = 0 ; i < ANSWERVECTOR.size() ; i++){
		string str = ANSWERMAP[ANSWERVECTOR[i]];
		answer.push_back(MAP[str].first_num);
		if(MAP[str].count > 1) answer.push_back(MAP[str].second_num);
	}


    return answer;
}

int main(){

	vector<string> genre;
	vector<int> play;

	genre.push_back("classic");
	genre.push_back("pop");
	genre.push_back("classic");
	genre.push_back("classic");
	genre.push_back("pop");

	play.push_back(500);
	play.push_back(600);
	play.push_back(150);
	play.push_back(800);
	play.push_back(2500);

	solution(genre, play);

	return 0;
}
