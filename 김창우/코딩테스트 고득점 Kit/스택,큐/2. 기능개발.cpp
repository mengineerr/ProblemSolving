#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct DATA{
	bool status;
	int progress, speed;
};

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int index = 0;
    int count = 0;
    int total = progresses.size();
    vector<DATA> MAP;

    for(int i = 0 ; i < progresses.size() ; i++){
    	DATA data;
    	data.status = false;
    	data.progress = progresses[i] + speeds[i];
    	data.speed = speeds[i];
    	if(data.progress >= 100){
    		data.status = true;
    		if(i == index){
    			index++;
    			count++;
    			total--;
    		}
    	}
    	MAP.push_back(data);
    }

    if(count > 0){
    	answer.push_back(count);
    	count = 0;
    }

    while(total > 0){
    	count = 0;
    	for(int i = 0 ; i < progresses.size() ; i++){
    		if(!MAP[i].status){
    			MAP[i].progress = MAP[i].progress + MAP[i].speed;
    			if(MAP[i].progress >= 100) MAP[i].status = true;
    		}
    		if(MAP[i].status && i == index){
    			index++;
    			count++;
    			total--;
    		}
    	}
    	if(count > 0) answer.push_back(count);
    }


    for(int temp : answer) cout << temp << " ";

    return answer;
}


int main(){

	vector<int> progress;
	vector<int> speed;

	progress.push_back(95);
	progress.push_back(90);
	progress.push_back(99);
	progress.push_back(99);
	progress.push_back(80);
	progress.push_back(99);

	speed.push_back(1);
	speed.push_back(1);
	speed.push_back(1);
	speed.push_back(1);
	speed.push_back(1);
	speed.push_back(1);

	solution(progress, speed);

	return 0;
}
