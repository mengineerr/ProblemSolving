# type도 == 등가확인 가능
  if type(100) == int:
  
# 문자열에서 숫자확인하기
  if str.isdigit():

# Python에서 순열과 조합은 구분
## 순열
  from itertools import permutations
  tmp = permutations(numbers,count)

## 조합
  from itertools import combinations
  tmp = combinations(numbers,count)
# str.split()
# list.remove("a")
# 대문자 소문자
# 리스트 문자열 전환
# 인덱스 에러 조심
