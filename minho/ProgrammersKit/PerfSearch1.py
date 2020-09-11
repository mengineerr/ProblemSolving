def solution(answers):
    answer = []
    person_list = [0] * 3
    
    if len(answers) > 5:
        tmp = len(answers) // 5 + 1
        person1 = [1,2,3,4,5] * tmp
    else:
        person1 = [1,2,3,4,5]
    if len(answers) > 8:
        tmp = len(answers) // 8 + 1
        person2 = [2,1,2,3,2,4,2,5] * tmp
    else:
        person2 = [2,1,2,3,2,4,2,5]
    if len(answers) > 10:
        tmp = len(answers) // 10 + 1
        person3 = [3,3,1,1,2,2,4,4,5,5] * tmp
    else:
        person3 = [3,3,1,1,2,2,4,4,5,5]
    
    
    for i in range(len(answers)):
        if answers[i] == person1[i]:
            person_list[0] += 1
        if answers[i] == person2[i]:
            person_list[1] += 1
        if answers[i] == person3[i]:
            person_list[2] += 1
    
    for i in range(0,3):
        if person_list[i] == max(person_list):
            answer.append(i+1)
    
    return answer
