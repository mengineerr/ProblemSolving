def solution(bridge_length, weight, truck_weights):
    answer = 0
    bridge_queue = [0] * bridge_length  # 리스트를 활용한 큐는 역순으로 활용하자
    
    while bridge_queue:
        answer += 1
        bridge_queue.pop(0)
        if not truck_weights:   # 남은 트럭이 없는 경우
            continue
        if sum(bridge_queue) + truck_weights[0] <= weight:  # 트럭이 더 올라올 수 있으면
            bridge_queue.append(truck_weights.pop(0))
        else:                                               # 무게가 초과된 경우
            bridge_queue.append(0)
    
    return answer
