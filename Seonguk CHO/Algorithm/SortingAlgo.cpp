#include <iostream>
#include <vector>

using namespace std;

/*
    선택 정렬

    선택 정렬은 이름에 맞게 현재 위치에 들어갈 값을 찾아 정렬하는 배열이다.
    기본 로직은 다음과 같다.
    1. 정렬 되지 않은 인덱스의 맨 앞에서 부터, 이를 포함한 그 이후의 배열값 중 가장 작은 값을 찾아간다.
    2. 가장 작은 값을 찾으면, 그 값을 현재 인덱스의 값과 바꿔준다.
    3. 다음 인덱스에서 위 과정을 반복해준다. 

    이 과정은 n-1개, n-2개, ... , 1개 씩 비교하여 시간복잡도는 O(N^2)

*/ 
void selectionSort(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        int temp = i;
        for(int j = i+1; j< v.size(); j++){
            if(v[temp]>=v[j]) temp = j;
        }
        swap(v[i], v[temp]);
    }
}
/*
    삽입 정렬

    삽입 정렬은 현재 위치에서, 그 이하의 배열들을 비교하여 자신이 들어갈 위치를 찾아, 그 위치에 삽입하는 배열 알고리즘
    기본 로직은 다음과 같다.
    1. 삽입 정렬은 두 번째 인덱스부터 시작한다. 현재 인덱스는 별도의 변수에 저장해주고, 비교 인덱스는 현재 인덱스 -1로 잡는다.
    2. 별도로 저장해 둔 삽입을 위한 변수와, 비교 인덱스 배열 값을 비교한다.
    3. 삽입 변수의 값이 더 작으면 현재 인덱스로 비교 인덱스의 값을 저장해주고, 비교 인덱스를 -1하여 비교를 반복한다.
    4. 만약 삽입 변수가 더 크면, 비교 인덱스+1에 삽입 변수를 저장한다. 

*/ 
void insertionSort(vector<int> v){
    for(int i = 1; i < v.size(); i++){
        int key = v[i], j = i -1;
        while (j>=0&&key<v[j]){
            swap(v[j], v[j+1]);
            j--;
        }
        v[j+1] = key;
    }
}
/*
    버블 정렬

    버블 정렬은 매번 연속된 두개 인덱스를 비교하여, 정한 기준의 값을 뒤로 넘겨 정렬하는 방법이다. 
    기본 로직은 다음과 같다.
    1. 버블 정렬은 두 번째 인덱스 부터 시작한다.
    2. 만약 이전 인덱스가 더 크면, 현재 인덱스와 바꿔준다.
    3. 현재 인덱스가 더 크면, 교환하지 않고 다음 두 연속된 배열값을 비교한다.
    4. 이를 전체 배열의 크기 - 현재까지 순환한 바퀴 수 만큼 반복한다.

*/ 
void bubbleSort(vector <int> v){
    for(int i = 0; i < v.size()-1; i++){
        for(int j = 1; j < v.size()-i;j++){
            if(v[j-1]>v[j]) swap(v[j-1], v[j]);
        }
    }
}
/*
    합병 정렬

    합병 정렬은 분할 정복(Divide and conquer) 방식으로 설계된 알고리즘이다. 분할 정복은 큰 문제를 반으로 쪼개 문제를 해결해 나가는 방식으로,
    분할은 배열의 크기가 1보다 작거나 같을 때까지 반복한다.
    합병은 두 개의 배열을 비교하여, 기준에 맞는 값을 다른 배열에 저장해 나간다.

    분할 과정의 기본 로직은 다음과 같다.
    1. 현재 배열을 반으로 쪼갠다. 배열의 시작 위치와, 종료 위치를 입력받아 둘을 더한후 2를 나눠 그 위치를 기준으로 한다.
    2. 이를 쪼갠 배열의 크기가 0이거나 1일때까지 반복한다.

    합병 과정의 기본 로직은 다음과 같다.
    1. 두 배열 A,B의 크기를 비교한다. 각각의 배열의 현재 인덱스를 i,j로 가정
    2. i에는 A배열의 시작 인덱스를 저장하고, j에는 B배열의 시작 주소를 저장한다.
    3. A[i]와 B[j]를 비교한다. 오름차순의 경우 이중에 작은 값을 새 배열 C에 저장한다.
    A[i]가 컸다면, A[i]의 값을 배열 C에 저장해주고, i의 값을 하나 증가시켜준다.
    4. 이를 i나 j 둘 중 하나가 각자 배열의 끝에 도달할 때 까지 반복한다.
    5. 끝까지 저장을 못한 배열의 값을 순서대로 전부 C에 저장한다.
    6. C배열을 원래의 배열에 저장해준다.


*/ 
void merge(vector<int> &v, int s, int e, int m){
    vector<int> ret;
    int i = s, j = m + 1, copy = 0;
    // 결과를 저장할 배열에 하나 씩 비교하여 저장
    while (i<=m&&j<=e)
    {
        if(v[i] < v[j]) ret.push_back(v[i++]);
        else if (v[i]> v[j]) ret.push_back(v[j++]);
    }
    // 남은 값들을 뒤에 채움
    while(i<=m) ret.push_back(v[i++]);
    while(j<=e) ret.push_back(v[j++]);
    // 원래 배열에 복사
    for(int k = s; k <= e; k++) v[j] = ret[copy++];
}

void mergeSort(vector<int> &v, int s, int e){
    if(s<e){
        int m = (s+e)/2;
        // divide
        mergeSort(v,s,m); // s부터 m까지
        mergeSort(v,m+1,e); // m+1 부터 e까지
        // conquer
        merge(v,s,e,m);
    }
}
/*
    퀵 정렬

    퀵 정렬 또한 분할 정복을 이용한다.pivot point라고 기준이 되는 값을 하나 설정함
    이 값을 기준으로 작은 값은 왼쪽, 큰 값은 오른쪽으로 옮기는 방식으로 정렬한다. 
    기본 로직은 다음과 같다.
    1. pivot point로 잡을 배열의 값을 하나 정한다. 보통 맨 앞이나, 맨뒤, 혹은 랜덤하게
    2. 분할을 진행하기에 앞서, 비교를 진행하기 위해 가장 왼쪽 배열의 인덱스를 저장하는 left변수, 가장 오른쪽 배열의
    인덱스를 저장하는 right 변수를 생성한다.
    3. right 부터 비교를 진행한다. 비교는 right가 left보다 클 때만 반복하며, 비교한 배열값이 pivot point보다 크면 right를 하나 감소하고
    비교를 반복한다.
    4. 그 다음 left부터 비교를 진행한다. 비교는 right가 left보다 클때만 반복, 
    비교한 배열값이 pivot point보다 작으면 left를 하나 증가시키고 비교를 반복한다. 
    5. left의 인덱스 값과 right 인덱스의 값을 바꿔준다.
    6. 3,4,5 과정이 left < right가 만족할 때까지 반복한다.
    7. 위 과정이 끝나면, left의 값과 pivot point를 바꿔준다. 
    8. 맨 왼쪽부터 left -1 까지, left+1부터 맨 오른쪽까지로 나눠 퀵 정렬을 반복한다.    

*/ 
void quickSort(vector<int> &v, int s, int e){
    int pivot = v[s];
    int bs = s, be = e;
    while(s<e){
        while(pivot<=v[e]&&s<e) e--;
        if(s>e) break;
        while(pivot>=v[s]&&s<e) s++;
        if(s>e) break;
        swap(v[s],v[e]);
    }
    swap(v[bs], v[s]);
    if(bs<s) quickSort(v,bs,s-1);
    if(bs>e) quickSort(v,s+1,be);
    }
int main(){
    vector <int> v = {7,9,1,5,4,6,3,50,8};
    selectionSort(v);
    insertionSort(v);
    bubbleSort(v);

    return 0;

}