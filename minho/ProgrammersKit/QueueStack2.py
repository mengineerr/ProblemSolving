def solution(progresses, speeds):
    answer = []
    days = []
    
    for i in range(len(progresses)):
        if (100-progresses[i]) % speeds[i] == 0:
            days.append((100-progresses[i]) // speeds[i])       # //는 정수 몫
        else:
            days.append(((100-progresses[i]) // speeds[i])+1)
    
    i = 0
    
    while(i < len(days)):
        print(i)
        cnt = 0
        for j in range(i,len(days)):
            if days[i] < days[j]:
                break
            else:
                cnt += 1
        answer.append(cnt)
        i += cnt
    
    
    return answer
