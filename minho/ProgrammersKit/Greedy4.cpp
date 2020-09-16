#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int a, int b){
    return a > b;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end(), desc);
    
    int start = 0;
    int last = people.size()-1;
    
    while(start <= last){
        answer += 1;
        
        int sum = people[start];
        
        if(start < last){
            while(sum < limit){
                int next = people[last];

                if(sum + next <= limit){
                    sum += next;
                    last--;
                }
                else
                    break;
            }
        }
        
        start++;
    }
    
    return answer;
}
