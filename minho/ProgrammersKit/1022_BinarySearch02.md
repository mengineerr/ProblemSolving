# Binary Search 02 / Helped
### How to solve
- 이분탐색 방식을 도입
- 중간값보다 거리가 작은 돌을 모두 제거했을 때 제거된 돌의 개수와 비교
- 연속된 돌의 제거가 중간값보다 작은 경우도 고려해야함

### 
    int left = 1;
    int right = distance;
    
    while(left <= right){
        int mid = (left + right) / 2;
        int idx = 0;
        int cnt = 0;
        
        for(int next : rocks){
            if(mid > next - idx)
                cnt++;
            else
                idx = next; // 연속된 돌의 거리가 mid보다 작을 수 있는 경우
        }
        
        if(cnt > n)
            right = mid - 1;
        else{
            left = mid + 1;
            answer = max(answer, mid);
        }
    }
