from itertools import permutations  # permutations 모델

def solution(numbers):
    answer = 0
    nums = []
    
    for i in range(1,len(numbers)+1):
        tmp = permutations(numbers,i)   # permutations 사용법
        for j in tmp:
            tmp_str = "".join(j)        # 문자열 이어붙이기
            if int(tmp_str) not in nums:
                nums.append(int(tmp_str))
    
    for num in nums:
        cnt = 0
        for i in range(2,num):
            if num % i == 0:
                cnt += 1
                break
        if num > 1 and cnt == 0:
            answer += 1
    
    return answer
