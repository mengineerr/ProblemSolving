import heapq

def solution(jobs):
    answer = 0
    now = 0
    last = -1
    cnt = 0
    works = []
    
    while cnt < len(jobs):
        for job in jobs:
            if last < job[0] <= now:            # now 때 대기열에 포함될 수 있는 모든 job 포함
                answer += now - job[0]
                heapq.heappush(works, job[1])
        if len(works) > 0:
            answer += len(works) * works[0]     # 다른 job이 기다리는 상황에도 시간은 함께 소요되므로 len(works)
            last = now
            now += heapq.heappop(works)
            cnt += 1
        else:
            now += 1
    
    return answer // len(jobs)
