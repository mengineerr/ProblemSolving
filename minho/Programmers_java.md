# Hash 01
라이브러리
```java
        import java.util.Arrays;
        import java.util.Collections;
```

자바에서 정렬 사용하기
```java
        Arrays.sort(participant);
        Arrays.sort(completion);
        // 역정렬이 필요하다면
        // Arrays.sort(participant, Collections.reverseOrder());
```

배열 형태 주의
```java
        String[] participant
```

배열 메소드 괄호 주의
```java
        for(int i = 0; i < completion.length; i++){ // 배열의 길이를 구할 때 괄호 미포함!
            if(!participant[i].equals(completion[i])){  // .equals() 메소드 기억하기
                return participant[i];
            }
        }
```

<br>

# Hash 02
startsWith() 방식
```java
        for(int i = 0; i < phone_book.length-1; i++){
            for(int j = i+1; j < phone_book.length; j++){
                
                if(phone_book[i].startsWith(phone_book[j])){    // startsWith() 메소드 
                    return false;   // 자바에서는 true, false 소문자 시작
                }
                if(phone_book[j].startsWith(phone_book[i])){
                    return false;
                }
                
            }
        }
```
HashCode() 방식
```java
        for(int i = 0; i < phone_book.length-1; i++){
            int cur_hash = phone_book[i].hashCode();    // hashCode() 메소드
            int cur_len = phone_book[i].length();   // 배열은 괄호가 없고, string은 괄호 포함
            
            for(int j = i+1; j < phone_book.length; j++){
                if(phone_book[j].length() >= cur_len && 
                   (cur_hash == phone_book[j].substring(0,cur_len).hashCode())){        // substring(0,len)
                    return false;
                }
                else if(phone_book[j].length() < cur_len && 
                        ((phone_book[i].substring(0,phone_book[j].length()).hashCode()) == phone_book[j].hashCode())){
                    return false;
                }
            }
        }
```
