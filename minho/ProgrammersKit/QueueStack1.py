def solution(prices):
    answer = [0] * len(prices)  # 미리 초기화
    
    for idx in range(0,len(prices)-1):
        cnt = 0
        for check in range(idx,len(prices)-1):
            if prices[idx] <= prices[check]:
                answer[idx] += 1
            else:
                break

    
    return answer
