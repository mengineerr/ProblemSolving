#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Queue{
    private:
        int *data;
        int idx_front;
        int idx_back;
        int len;
    public:
        Queue(int x);
        int empty();
        void push(int x);
        void pop();
        int front();
        int back();
        int size();
};

Queue::Queue(int x){
    data = new int[x];
    idx_back = 0;
    idx_front = 0;
    len =x;
}

int Queue::empty(){
    if(idx_front == idx_back){
        return 1;
    }
    else return 0;
}

void Queue::push(int x){
    data[idx_back] = x;
    idx_back = (idx_back+1)%len;

    //std::cout << data[idx_back] << "\n";
}

void Queue::pop(){
    std::cout << data[idx_front] << "\n";
    
    idx_front = (idx_front+1)%len;
}

int Queue::front(){
    return data[idx_front];
}

int Queue::back(){
    return data[idx_back-1];
}

int Queue::size(){
    return sizeof(data)/sizeof(int);
}



int main()
{
    int N;
    cin >> N;

    Queue q(N);

    string str;

    for(int i = 0; i<N; i++){
        cin >> str;

        if(str == "push"){
            int num = 0;
            cin >> num;
            q.push(num);
        }
        else if(str == "pop"){
            if(!q.empty()){
                q.pop();
            }
            else{
                std::cout << -1 << "\n";
            }
        }
        else if(str == "size"){
            if(!q.empty()) std::cout << q.size() << "\n";
            else std::cout << 0 << "\n";
        }
        else if(str == "empty"){
            std::cout << q.empty() << "\n";
        }
        else if(str == "front"){
            if(!q.empty()){
                std::cout << q.front() << "\n";
            }
            else{
                std::cout << -1 << "\n";
            }
        }
        else if(str == "back"){
            if(!q.empty()){
                std::cout << q.back() << "\n";
            }
            else{
                std::cout << -1 << "\n";
            }
        }
    }
    
}