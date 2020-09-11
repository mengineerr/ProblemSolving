import heapq    # heapq 매우 빠른 우선순위 큐

def solution(scoville, K):
    answer = 0
    
    heap = []
    
    for num in scoville:
        heapq.heappush(heap,num) # push
        
    while heap[0] < K:
        try:
            heapq.heappush(heap, heapq.heappop(heap) + heapq.heappop(heap) * 2) # push & pop
        except IndexError:  # IndexError 사용법
            return -1
        answer += 1
            
    return answer
