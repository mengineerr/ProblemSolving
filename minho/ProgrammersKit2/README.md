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
    for name, kind in clothes:
        if kind not in cloth_dict:
            cloth_dict[kind] = 1    # 개수만 알면되므로 리스트가 아닌 숫자로 사용
        else:
            cloth_dict[kind] += 1   # 리스트를 쓰게되면 append에서 시간적 비효율
```

```python
    for kind, value in cloth_dict.items():
        if answer == 0:
            answer += value + 1
        else:
            answer *= (value + 1)   # (종류 + 안입는경우) 중복순열 아이디어
    
    return answer - 1   # 아무것도 안입는 경우 제외
```

<br>

## Hash 04
- list comprehension 다양한 방법
- 리스트, 딕셔너리 정렬방법

```python
    # Dictionary 기본 베이스를 List Comprehension으로 만드는 방법
    # total_dict = {e:[] for e in set(genres)}
    total_dict = {}
    idx_dict = {}
    index = 0
```

```python
    # index 변수를 사용하지 않고 zip(genres, plays, range(len(genres)))를 사용하면 더 편하다
    for genre, play in zip(genres, plays):
        if genre not in total_dict:
            total_dict[genre] = play
        else:
            total_dict[genre] += play
        
        if genre not in idx_dict:
            idx_dict[genre] = [(play, index)]
        else:
            idx_dict[genre].append((play, index))
        
        index +=1
```

```python
    # Dictionary value기준 역정렬
    sorted_dict = sorted(total_dict.items(), key=lambda x : x[1], reverse=True) 
    
    # dictionary의 for loop는 key가 기준
    for genre in sorted_dict:
        cnt = 2
        play_list = idx_dict[genre[0]]
        play_list.sort(key=lambda x: (-x[0], x[1])) # 값 기준 정렬 후 고유 번호가 낮게 나오도록 재정렬
        for play, loc in play_list:
            if cnt <= 0:
                continue
            answer.append(loc)
            cnt -= 1
```
