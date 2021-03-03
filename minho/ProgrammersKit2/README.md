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
