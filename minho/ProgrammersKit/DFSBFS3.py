min = 987654321

def bfs(cur, target, words):
    global min
    
    que = [[cur,0]]
    check_list = [0] * len(words)
    
    while que:
        cur_list = que.pop(0)
        
        if cur_list[0] == target:
            if min > cur_list[1]:
                min = cur_list[1]
        
        for i in range(len(words)):
            cnt = 0
            for j in range(len(words[i])):
                if words[i][j] != cur_list[0][j]:
                    cnt += 1
            if cnt == 1 and check_list[i] == 0:
                check_list[i] = 1
                que.append([words[i],cur_list[1]+1])
    
def solution(begin, target, words):
    global min
    str_len = len(begin)
    
    bfs(begin,target,words)
    
    answer = min
    if answer == 987654321:
        answer = 0
    
    return answer
