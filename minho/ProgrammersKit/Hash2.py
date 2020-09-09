def solution(phone_book):
    answer = True
    
    phone_book.sort()
    
    for i in range(0,len(phone_book)):
        print(phone_book[i])
        for j in range(i+1, len(phone_book)):
            # 문자열도 in 으로 부분포함 확인
            """
            if phone_book[i] in phone_book[j]:  
                return False
            """
            # 전방일치 : str.startswith(('aaa', 'bbb', 'ccc'))
            # 후방일치 : str.endswith(('aaa', 'bbb', 'ccc'))
            if phone_book[j].startswith(phone_book[i]):     
                return False
    
    return answer
