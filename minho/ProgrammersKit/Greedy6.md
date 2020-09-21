# 단속카메라 (Helped)
### How to solve
- 카메라의 진입, 진출 지점을 기준으로 설정
- 정렬이 필수

### 카메라 설치 알고리즘
    do{
        if(idx == 0){
            loc = routes[0][1];
            idx++;
            continue;
        }
        
        if(routes[idx][1] < loc){   // 다음 경로 진출지점이 이전 경로 진출보다 짧은 경우
            loc = routes[idx][1];
        }
        else if(routes[idx][0] > loc){  // 카메라 위치가 다음 경로 진입지점보다 이전인 경우
            answer++;
            loc = routes[idx][1];
        }
        
        idx++;
    }while(idx < routes.size());
