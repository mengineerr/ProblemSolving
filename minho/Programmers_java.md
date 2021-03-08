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
