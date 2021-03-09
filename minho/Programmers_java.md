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
startsWith() 방식 : 2순위(실패)
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
HashCode() 방식 : 3순위(실패), hashCode()메소드가 추가됐을 뿐 Big-O에는 차이가 없어서 그런것 같다
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
String 정렬을 수행해서 유사한 문자열끼리 정렬하고 비교하는 방식 (정답)
```java
import java.util.Arrays;

class Solution {
    public boolean solution(String[] phone_book) {
        Arrays.sort(phone_book);
        boolean result = true;
        for (int i=0; i<phone_book.length-1; i++) {
            if (phone_book[i+1].startsWith(phone_book[i])) {
                result = false;
                break;
            }
        }
        return result;
    }
}
```

<br>

# Hash03
Map 사용법
```java
import java.util.Map;
import java.util.HashMap;
import java.util.Iterator;

        Map<String, Integer> map = new HashMap<String, Integer>();
        
        for(String[] s: clothes){
            int temp = 0;
            if(map.containsKey(s[1]))   // map.containsKey(key) 키가 존재하는 지 확인
                temp = map.get(s[1]);   // map.get(key)    해당하는 key의 value를 가져오는 메소드
            map.put(s[1], temp+1);      // map.put(String, Integer) map에 값을 넣는 메소드
                                        // key 중복시 새로운 값으로 대체된다
        }
```
Iterator 사용법
```java
        // Iterator는 모든 컬렉션 프레임워크에 공통으로 사용 가능
        Iterator<Integer> it = map.values().iterator();
        
        while(it.hasNext()) {   // Iterator.hasNest()   다음 요소가 있는지 확인하는 메소드
            answer *= it.next().intValue()+1;   // Iterator.next() 다음 요소를 가져온다
            // Integer.intValue()   Integer 객체에서 int형 값을 뽑아내는 메소드
            //  Integer.parseInt(str)   String형 객체에서 int형 값을 뽑아 내는 메소드
        }
```

<br>

# Hash04
모든 코드 다시
```java
import java.util.HashMap;
import java.util.Map;
import java.util.Iterator;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class Solution {
    public int[] solution(String[] genres, int[] plays) {

        Map<String, Object> genres_map = new HashMap<String, Object>(); // Object 자체로도 선언 가능
        Map<String, Integer> total_map = new HashMap<String, Integer>();
        
        for(int i = 0; i < genres.length; i++){
            HashMap<Integer, Integer> temp_map;
            
            if(!genres_map.containsKey(genres[i])){ // map.containsKey()
                temp_map = new HashMap<Integer, Integer>(); // Object에 HashMap<Integer, Integer>() 을 넣는 방식
            }
            else{
                temp_map = (HashMap<Integer, Integer>)genres_map.get(genres[i]);
            }
            
            temp_map.put(i, plays[i]);
            genres_map.put(genres[i], temp_map);
            
            if(!total_map.containsKey(genres[i])){
                total_map.put(genres[i], plays[i]);
            }
            else{
                total_map.put(genres[i], (total_map.get(genres[i]) + plays[i]));
            }
        }
        
        // Iterator<String> it = total_map.keySet().iterator();    // map.keySet().iterator() : key 가져오는 메소드
        Iterator it = sortByValue(total_map).iterator();    // 정렬함수를 직접 만들어서 사용한 경우
        ArrayList<Integer> result = new ArrayList<Integer>(); 
        
        while(it.hasNext()){
            String key = (String)it.next();
            
            Iterator choice = sortByValue((HashMap<Integer, Integer>)genres_map.get(key)).iterator();
            int cnt = 0;
            
            while(choice.hasNext()){
                if(cnt >= 2)
                    break;
                int loc = (int)choice.next();
                result.add(loc);
                cnt++;
            }
        }
        
        int[] answer = new int[result.size()];
        
        for(int i = 0; i < result.size(); i++)
            answer[i] = result.get(i).intValue();   // ArrayList.get(index).intValue() : ArrayList에서 int값을 가져오는 경우
        
        
        return answer;
    }
    
    public static ArrayList sortByValue(final Map map){
        ArrayList<String> key_list = new ArrayList();
        key_list.addAll(map.keySet());  // ArrayList.addAll() : 인자로 전달되는 Collection 객체의 모든 아이템을 리스트에 추가
        
        Collections.sort(key_list, new Comparator(){    // 정렬 비교 함수, 기억해두자
            public int compare(Object o1, Object o2){
                Object v1 = map.get(o1);
                Object v2 = map.get(o2);
                
                return ((Comparable)v2).compareTo(v1);
            }
        });
        
        // Collections.reverse(key_list)   // 오름차순을 원할 시
        
        return key_list;
    }
}
```

<br>

# Stack/Queue 01
- class 활용
- Queue 메소드 확인

```java
import java.util.Queue;
import java.util.LinkedList;

class Solution {
    class Truck{
        int weight;
        int distance;
        
        public Truck(int _weight){
            this.weight = _weight;
            this.distance = 0;
        }
        
        public void move(){
            this.distance += 1;
        }
    }
    
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        Queue<Truck> wait_truck = new LinkedList<>();
        Queue<Truck> moving_truck = new LinkedList<>();
        
        for(int w: truck_weights){
            Truck temp = new Truck(w);
            wait_truck.offer(temp); // 자바에서는 Queue.offer() / Queue.poll() / Queue.peek()
        }
        
        int total_weight = 0;
        
        while(!wait_truck.isEmpty() || !moving_truck.isEmpty()){
            answer++;
            
            if(!moving_truck.isEmpty())
                for (Truck tmp : moving_truck)
                    tmp.move();
            
            if(!moving_truck.isEmpty() && moving_truck.peek().distance > bridge_length){
                Truck tmp = moving_truck.poll();
                total_weight -= tmp.weight;
            }
            
            if(!wait_truck.isEmpty() && total_weight + wait_truck.peek().weight <= weight){
                Truck tmp = wait_truck.poll();
                total_weight += tmp.weight;
                tmp.move();
                moving_truck.offer(tmp);
            }
            
        }
        
        return answer;
    }
}
```
