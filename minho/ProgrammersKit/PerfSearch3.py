def solution(brown, yellow):
    answer = []
    total = brown + yellow
    
    for i in range(2,total):
        if total % i != 0:
            continue
        row = i
        col = total / i
        if brown == (2 * (row + col) - 4):
            answer = [row,col]
    
    answer.sort(reverse = True)
    
    return answer
