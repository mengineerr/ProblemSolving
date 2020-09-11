def solution(citations):
    answer = 0
    citations.sort()
    
    for num in range(0,max(citations)+1):   # max(citations) 보다 len(citations)가 낮은 경우 참고
        high = 0
        low = 0
        for citation in citations:
            if citation >= num:
                high += 1
            elif citation < num:
                low += 1
        if low <= num and high >= num:
            answer = num
        
    return answer
