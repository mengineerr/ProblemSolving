def solution(n, computers):
    answer = 0
    visit = [0] * n      
    
    for i in range(n):
        if visit[i] == 0:
            answer += 1
            que = [i]
            while que:
                cur = que.pop(0)
                if visit[cur] == 0:
                    visit[cur] = 1
                for j in range(n):
                    if computers[cur][j] == 1 and visit[j] == 0:
                        visit[j] = 1
                        que.append(j)
    
    return answer
