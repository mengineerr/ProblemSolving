#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<char> alphaVec;

void cal(int num, string str, int mo, int ja){
	if(str.size() == L){
		if(mo >= 1 && ja >= 2) cout << str << "\n";
	}
	for(int i = num ; i < C ; i++){
		if(alphaVec[i] == 'a' || alphaVec[i] == 'e' || alphaVec[i] == 'i' || alphaVec[i] == 'o' || alphaVec[i] == 'u'){
			cal(i + 1, str + alphaVec[i], mo + 1, ja);
		}else{
			cal(i + 1, str + alphaVec[i], mo, ja + 1);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> L >> C;

	for (int i = 0 ; i < C ; i++){
		char temp;
		cin >> temp;
		alphaVec.push_back(temp);
	}

	sort(alphaVec.begin(), alphaVec.end());

	cal(0, "", 0, 0);

    return 0;
}
