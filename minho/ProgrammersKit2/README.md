# ProgrammersKit

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

## Stack/Queue 01
- collection 모듈을 활용하자
- for _ in range(something):
- 리스트 sum()메소드는 시간을 늘리는 주범!

```python
    cur_bridge = deque(0 for _ in range(bridge_length)) # 단순히 리스트보다는 deque를 활용하자
```

```python
    while truck_weights:
        total -= cur_bridge.popleft()
        
        if total + truck_weights[0] > weight:
            cur_bridge.append(0)
        else:
            cur_truck = truck_weights.pop(0)
            total += cur_truck
            cur_bridge.append(cur_truck)
        
        answer += 1
```

```python
    """ 단순히 한칸씩 옮기는 과정으로 비효율적이다
    while total > 0:
        total -= cur_bridge.popleft()
        cur_bridge.append(0)
        answer += 1
    """
    
    # 메인 루프의 모든 과정이 끝나면 최종 트럭이 다리의 첫 위치에 위치하게 된다
    # 이 트럭만 도착하면 되므로 bridge_length만큼의 시간이 필요하다
    answer += bridge_length 
```

## Stack/Queue 02
- 변수에 할당해서 메소드의 반복을 줄이자
```python
    answer = [0 for _ in prices]
    prices_len = len(prices)
    
    for i in range(prices_len-1):   # 변수 활용
        answer[i] += 1
        idx = i+1
        
        while idx <= (prices_len - 2):  # 변수 활용
            if prices[idx] < prices[i]:
                break
            else:
                answer[i] += 1
            idx += 1
```

## Permutations / Combinations
- from itertools import permutations(combinations)
```python
    import itertools

    pool = ['A', 'B', 'C']
    print(list(map(''.join, itertools.permutations(pool)))) # 3개의 원소로 수열 만들기
    print(list(map(''.join, itertools.permutations(pool, 2)))) # 2개의 원소로 수열 만들기
```

## Stack/Queue 03
- 리스트를 while 반복문 판별에 활용하자

```python
    while progresses:
        if progresses[0] + speeds[0] * date >= 100:
            cnt += 1
            progresses.pop(0)
            speeds.pop(0)
        else:
            if cnt > 0:
                answer.append(cnt)
                cnt = 0
            date += 1
```

## Stack/Queue 04
```python
    p_list = [(p, i) for i,p in enumerate(priorities)]  # enumerate() 메소드
```

```python
    while d:
        cur = d.popleft()
        
        if any(cur[0] < e[0] for e in d):   # any() 메소드 / deque도 for문 가능
            d.append(cur)
        else:
            answer += 1
            if cur[1] == location:
                break
```
