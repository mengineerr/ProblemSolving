#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long max = 0; long long min = 1;
    
    for(int i = 0; i < times.size(); i++){
        if(times[i] > max)
            max = times[i];
    }
    
    //min *= n;
    max *= n;
    
    while(min <= max){
        long long avg = (max + min) / 2;
        long long customer = 0;
        
        for(int next: times) customer += avg / next;
        
        if(customer >= n){
            answer = avg;
            max = avg - 1;
        }
        else
            min = avg + 1;
    }
    
    
    return answer;
}
