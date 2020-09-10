# import operator

def solution(genres, plays):
    answer = []
    total = {}
    kinds = {}
    
    for i in range(0,len(genres)):
        if genres[i] not in total:
            total[genres[i]] = 0
        if genres[i] not in kinds:
            kinds[genres[i]] = []
        total[genres[i]] += plays[i]
        kinds[genres[i]].append((i,plays[i]))
    
    #total_reverse = sorted(total.items(), reverse = True, key = operator.itemgetter(1)) # operator 모듈 사용법
    total_reverse = sorted(total.items(), reverse = True, key=lambda x: x[1])
    
    for genre in total_reverse:
        play_list = kinds[genre[0]]
        print(play_list)
        play_list = sorted(play_list, key = lambda x : (-x[1],x[0]))   # lambda 정렬 사용법 / 중복적용도 가능
        
        print(play_list)
        
        for i in range(0,len(play_list)):
            if i == 2:
                break
            answer.append(play_list[i][0])
    
    """
    test = [(7,700),(5,700),(3,1000)]
    test = sorted(test, key = lambda x : (x[0],-x[1]))
    print(test)
    """
    
    return answer
