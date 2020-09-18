# 섬연결하기 (Helped)
### How to solve
- Kruskal Algorithm을 활용하여 cycle 여부를 확인하는 방식으로 MST를 구현한다
- 구현 이전 Sorting 잊지말자

### getParent: 부모노드를 리턴하는 함수
    int getParent(int x){
        if(parent[x] == x)
            return x;
        else
            return parent[x] = getParent(parent[x]);
    }
  
### find: 각 노드의 부모노드가 동일한지 확인하는 함수
    int find(int a, int b){
        a = getParent(a);
        b = getParent(b);
        if(a == b)
            return 1;
        else
            return 0;
    }
  
### unionParent: 연결 후 부모노드를 동일하게 설정
    void unionParent(int a, int b){
        a = getParent(a);
        b = getParent(b);
        if(a < b)
            parent[b] = a;
        else
            parent[a] = b;
    }

### MST 알고리즘
    for(auto next: costs){
        if(!find(next[0],next[1])){
            answer += next[2];
            unionParent(next[0],next[1]);
        }
    }
