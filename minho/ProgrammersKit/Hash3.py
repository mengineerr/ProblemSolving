def solution(clothes):
    answer = 1
    dic = {}
    clothes.reverse()
    list = []
    
    for i in clothes:
        i.reverse()             # 리스트 순서 변환
        if i[0] not in dic:     # 딕셔너리 Key 포함 여부 확인
            dic[i[0]] = []
        dic[i[0]].append(i[1])

    for i in dic:
        list.append(len(dic[i]))
    
    for i in list:
        answer *= (i+1)         # 안입는 경우도 포함해서 중복순열처럼 계산
    
    answer -= 1                 # 모두 안입는 경우 제외
    
    return answer
