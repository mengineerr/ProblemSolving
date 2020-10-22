# 입국심사 / Helped
### How to solve
- 시간이 경과하면서 심사관의 작업량을 따지는 방법보다
- 기준 시간 내에 심사관이 몇명의 손님을 받을 수 있는지 확인하는 방법이 더 경제적

### 심사 인원 확인
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
