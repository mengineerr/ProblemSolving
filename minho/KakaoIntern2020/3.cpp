#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct loc{
    int start; int last; int length;
};

bool compare(loc a, loc b){
    if(a.length == b.length){
        return a.start < b.start;
    }
    else{
        return a.length < b.length;
    }
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<string> kinds;   // 보석 종류
    vector<loc> candidates;
    
    for(string next:gems){
        if(find(kinds.begin(),kinds.end(),next) == kinds.end()){
            kinds.push_back(next);
        }
    }
    
    /*
    for(string next : kinds)
        printf("%s\n", next.c_str());   // vector string printf() 함수 사용시 c_str() 필요
    */
    
    for(int i = 0; i < gems.size(); i++){
        int cnt = 0;
        vector<string> tmp;
        
        if(gems.size() - i < kinds.size())  // 큰 영향 없음
            break;
        
        for(int j = i; j < gems.size(); j++){
            if(find(tmp.begin(),tmp.end(),gems[j]) == tmp.end()){
                tmp.push_back(gems[j]);
            }
            
            if(tmp.size() == kinds.size()){
                if(candidates.size() > 0 && candidates[0].length > j-i){
                    candidates.push_back({i+1,j+1,j-i});
                    sort(candidates.begin(),candidates.end(),compare);
                }
                else
                    candidates.push_back({i+1,j+1,j-i});
                    
                break;
            }
        }
    }
    
    answer.push_back(candidates[0].start);
    answer.push_back(candidates[0].last);
    
    return answer;
}
