def solution(numbers):
    answer = ''
    numbers = list(map(str, numbers))   # list 문자열 변경방법
    answer = "".join(sorted(numbers, key=lambda x: (x[0], x[1%len(x)], x[2%len(x)], x[3%len(x)]),reverse=True)) # lamda 문자열 + join
    return answer if int(answer) != 0 else "0" # if문 단일문장
