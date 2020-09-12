def solution(tickets):
    answer = []
    dicts = {}
    
    for ticket in tickets:
        if ticket[0] in dicts:
            dicts[ticket[0]].append(ticket[1])
        else:
            dicts[ticket[0]] = [ticket[1]]
    
    for key in dicts.keys():    # 딕셔너리 키 얻기
        dicts[key].sort(reverse = True)
    
    st = ["ICN"]
    
    while st:
        cur = st[-1]
        
        if cur not in dicts or len(dicts[cur]) == 0:
            answer.append(st.pop())
        else:
            st.append(dicts[cur][-1])
            dicts[cur].pop()
    
    answer.reverse()    # list 뒤집기
    
    return answer
