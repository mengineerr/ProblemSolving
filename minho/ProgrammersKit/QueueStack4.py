def solution(priorities, location):
    answer = 1
    stored_list = []
    
    for i in range(len(priorities)):
        if i == location:
            stored_list.append([priorities[i],1])
        else:
            stored_list.append([priorities[i],0])
    
    while stored_list:
        cur = stored_list.pop(0)
        if not stored_list:             # 대기목록이 없는 경우
            continue
        if cur[0] >= max(stored_list)[0]:   # 이중 리스트의 경우 max를 사용하면 0번 인덱스를 기준으로 정렬
            if cur[1] == 1:
                return answer
            else:
                answer += 1
        else:
            stored_list.append(cur)
    
    return answer
