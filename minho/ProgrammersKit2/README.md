# ProgrammersKit(2021-03-03)

## Hash 01
- 문자열의 길이가 일정한지 확인 필요
- zip()메소드
```python
    participant.sort()
    completion.sort()
    
    for part, comp in zip(participant, completion):
        if part != comp:
            return part
```

<br>

## Hash 02
- 문자열 길이별 정렬
```python
    # 리스트 길이별 정렬
    phone_book.sort(key=lambda x: len(x))
```

<br>

## Hash 03
- 알고리즘의 효율을 위해 불필요한 과정을 줄이자
- 리스트 메소드의 활용을 줄여 시간적 비효율을 개선한 방법

``` python
def solution(clothes):
    answer = 0
    
    cloth_dict = {}
    
    for name, kind in clothes:
        if kind not in cloth_dict:
            cloth_dict[kind] = 1    # 개수만 알면되므로 리스트가 아닌 숫자로 사용
        else:
            cloth_dict[kind] += 1   # 리스트를 쓰게되면 append에서 시간적 비효율
    
    for kind, value in cloth_dict.items():
        if answer == 0:
            answer += value + 1
        else:
            answer *= (value + 1)   # (종류 + 안입는경우) 중복순열 아이디어
    
    return answer - 1   # 아무것도 안입는 경우 제외
```

<br>

