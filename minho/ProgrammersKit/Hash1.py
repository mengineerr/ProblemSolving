def solution(participant, completion):
    answer = ''
    
    participant.sort()  // sort() 메소드
    completion.sort()
    
    for i in range(0, len(completion)):
        if participant[i] != completion[i]:
            answer = participant[i]
            return answer
    
    answer = participant[len(participant)-1]  // len() 메소드
    
    return answer
