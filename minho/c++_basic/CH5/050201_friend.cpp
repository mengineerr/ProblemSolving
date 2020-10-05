class A {
    int x;

    friend B; 
};

class B{
    int y;

};

//B는 x에 접근 가능하지만, A는 y에 접근 불가
//짝사랑 개념으로 이해

int main()
{

    return 0;
}