# Greedy4 구명보트
### How to Solve
- C++ STL 과용 시 시간적 비효율이 높게 발생
- 벡터 내 무게를 내림차순으로 정렬하여 최소 과정 유도
- Vector를 비우는 방법으로 사용시 매 과정마다 Vector의 삭제가 일어나 비효율
- Start, Last 인덱스를 활용하여 벡터의 변화없이 확인

### Indexing Operation
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
