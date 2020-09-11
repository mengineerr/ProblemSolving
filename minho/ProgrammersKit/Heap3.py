import heapq

def solution(operations):
    answer = []
    oper = []
    
    for operation in operations:
        if operation[0] == "I":
            heapq.heappush(oper, int(operation[2:]))
        elif operation == "D 1" and oper:
            oper.pop()
            # oper.remove(max(oper))
        elif operation == "D -1" and oper:
            # oper.pop(0)
            # oper.remove(min(oper))
            heapq.heappop(oper)
        
    if oper:
        answer = [max(oper), min(oper)]     # 리스트는 힙큐를 사용해도  min max를 활용하자
    else:
        answer = [0,0]
    
    return answer
