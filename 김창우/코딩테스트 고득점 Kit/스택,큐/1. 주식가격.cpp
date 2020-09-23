#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    
    vector<int> answer;

    for(int i = 0 ; i < prices.size() ; i++){
    	int count = 0;
    	for(int j = i + 1 ; j < prices.size() ; j++){
    		count++;
    		if(prices[j] < prices[i]) break;
    	}
    	answer.push_back(count);
    }

    for(int temp : answer) cout << temp << " ";

    return answer;
}


int main(){

	vector<int> price;

	price.push_back(1);
	price.push_back(2);
	price.push_back(3);
	price.push_back(4);
	price.push_back(5);
	price.push_back(5);
	price.push_back(5);
	price.push_back(5);
	price.push_back(5);
	price.push_back(5);
	price.push_back(5);
	price.push_back(5);
	price.push_back(5);
	price.push_back(3);
	price.push_back(4);
	price.push_back(5);
	price.push_back(5);
	price.push_back(5);
	price.push_back(5);
	price.push_back(5);
	price.push_back(5);
	price.push_back(5);
	price.push_back(5);
	price.push_back(5);
	price.push_back(5);

	solution(price);

	return 0;
}
